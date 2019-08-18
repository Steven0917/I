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

namespace PUMA {
namespace Kernel {

    
MessageSender::MessageSender(Context& context) : mContext(context)
{
}

MessageSender::~MessageSender()
{
}


void MessageSender::SendRegReq()
{
    string name, address, timestamp;
	mContext.mpHandler->mNetworker.GetHostNameAddr(name, address);
    char *userName = getenv("USERNAME");
    stringstream ss;
    string user_id;
    ss << userName;
    ss >> user_id;

    Request* req = new Request();
    RegisterRequest* reg = new RegisterRequest();
    reg->set_name(name);
    reg->set_user_id(user_id);
    reg->set_address(address);
    reg->set_version(PUMA_KERNEL_VER);
    reg->set_timestamp(timestamp);
    req->set_allocated_register_(reg);
    SendRequest(req, MSG::Register_Request);
}

void MessageSender::SendRegRsp(int kernelId, bool result)
{
    Response* rsp = new Response();
    RegisterResponse* reg = new RegisterResponse();

    reg->set_kernel_id(kernelId);
    rsp->set_result(result);
    rsp->set_allocated_register_(reg);
    SendResponse(rsp, MSG::Register_Response);
}


void MessageSender::SendHeartBeatReq()
{
    Request* req = new Request();
    HeartbeatRequest* hb = new HeartbeatRequest();
    hb->set_ts(time(nullptr));
    req->set_allocated_heart_beat(hb);
    SendRequest(req, MSG::Heartbeat_Request);
}


void MessageSender::SendHeartBeatRsp()
{
    Response* rsp = new Response();
    HeartbeatResponse* hb = new HeartbeatResponse();
    //hb->set_kernel_id(kerner_id);
    rsp->set_allocated_heart_beat(hb);
    SendResponse(rsp, MSG::Heartbeat_Response);
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
	mContext.mpHandler->mNetworker.Send(buf, size);
}

}  // namespace Kernel
}  // namespace PUMA