#include "network_handler.h"
#include "server_config.h"
#include "glog/logging.h"

#define MSG_HDR_SIZE 4

using namespace google::protobuf;

namespace PUMA {
namespace Kernel {

NetworkHandler::NetworkHandler(Networker& networker) : mNetworker(networker)
{
}

NetworkHandler::~NetworkHandler()
{
}

shared_ptr<Message> NetworkHandler::RecvMsg()
{
	char hdr[MSG_HDR_SIZE];
	memset(hdr, 0, MSG_HDR_SIZE);
	if (mNetworker.Peek(hdr, MSG_HDR_SIZE))
	{
		uint32 siz;
		io::ArrayInputStream ais(hdr, 4);
		io::CodedInputStream coded_input(&ais);
		coded_input.ReadVarint32(&siz);

		scoped_ptr<char> Buffer(new char[siz + MSG_HDR_SIZE]);
		char* buf = Buffer.get();
		memset(buf, 0, siz);

		//LOG(INFO) << "Receiving : " << siz + MSG_HDR_SIZE << " bytes.";

		NW_STATUS ret = mNetworker.Receive(buf, siz + MSG_HDR_SIZE);
		if (ret != NW_OK)
		{
			LOG(ERROR) << "Receiving " << siz + MSG_HDR_SIZE << " failed: " << ret;
			return shared_ptr<Message>(nullptr);
		}

		{
			shared_ptr<Message> msg = make_shared<Message>();
			io::ArrayInputStream ais(buf, siz + MSG_HDR_SIZE);
			io::CodedInputStream coded_input(&ais);
			coded_input.ReadVarint32(&siz);
			io::CodedInputStream::Limit msgLimit = coded_input.PushLimit(siz);
			msg->ParseFromCodedStream(&coded_input);
			//Once the embedded message has been parsed, PopLimit() is called to undo the limit
			coded_input.PopLimit(msgLimit);

			LOG(INFO) << "-> " << msg->description() << "(" << msg->type() << ")";
			return msg;
		}
	}

	return shared_ptr<Message>(nullptr);
}

void NetworkHandler::SendMsg(shared_ptr<Message>& msg)
{
	int size = msg->ByteSize() + MSG_HDR_SIZE;
	scoped_ptr<char> Buffer(new char[size]);
	char* buf = Buffer.get();
	memset(buf, 0, size);
	google::protobuf::io::ArrayOutputStream aos(buf, size);
	io::CodedOutputStream *coded_output = new io::CodedOutputStream(&aos);
	coded_output->WriteVarint32(msg->ByteSize());
	msg->SerializeToCodedStream(coded_output);

	LOG(INFO) << "<- " << msg->description() << "(" << msg->type() << "), " << size << " bytes.";
	mNetworker.Send(buf, size);
}


}  // namespace Kernel
}  // namespace PUMA