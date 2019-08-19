#include "version.h"
#include "context.h"
#include "message_types.h"
#include "message_sender.h"
#include "networker.h"
#include "glog/logging.h"
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

#define MSG_HEADER_SIZE 4
using namespace google::protobuf;
using namespace google::protobuf::io;

namespace Game {
namespace PSR {
    
MessageSender::MessageSender()
{
}

MessageSender::MessageSender(Networker& networker) : mNetworker(networker)
{
}

void MessageSender::SetNetworker(Networker& networker)
{
    mNetworker = networker;
}

MessageSender::~MessageSender()
{
}


/* Common Sender Operations */
void MessageSender::SendRequest(Request* req, MSG type)
{
    shared_ptr<Message> msg(new Message());
    msg->set_type(type);
    msg->set_description(MessageTypes::GetType(type));
    msg->set_allocated_request(req);
    SendMsg(msg);
}

void MessageSender::SendResponse(Response* rsp, MSG type)
{
    shared_ptr<Message> msg(new Message());
    msg->set_type(type);
    msg->set_description(MessageTypes::GetType(type));
    msg->set_allocated_response(rsp);
    SendMsg(msg);
}

void MessageSender::SendMsg(shared_ptr<Message>& msg)
{
    int size = msg->ByteSize() + MSG_HEADER_SIZE;
    shared_ptr<char> Buffer(new char[size]);
    char* buf = Buffer.get();
    memset(buf, 0, size);
    google::protobuf::io::ArrayOutputStream aos(buf, size);
    shared_ptr<CodedOutputStream> coded_output(new CodedOutputStream(&aos));
    coded_output->WriteVarint32(msg->ByteSize());
    msg->SerializeToCodedStream(coded_output.get());

    LOG(INFO) << "<-- " << msg->description() << "(" << msg->type() << "), " << size << " bytes.";
	mNetworker.Send(buf, size);
}

}  // namespace PSR
}  // namespace Game
