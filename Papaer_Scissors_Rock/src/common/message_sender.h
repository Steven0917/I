#pragma once

#include "message.pb.h"
#include "networker.h"
#include <memory>

using std::shared_ptr;

namespace PUMA {
namespace Kernel {

class Context;
class MessageSender
{
public:
    void SendRegReq();
    void SendRegRsp(int kernel_id, bool result = true);

    void SendHeartBeatReq();
    void SendHeartBeatRsp();

    MessageSender(Context& context);
    virtual ~MessageSender();

private:
    void SendRequest(Request* req, MSG type);
    void SendResponse(Response* rsp, MSG type);
    void SendMsg(shared_ptr<Message>& msg);

private:
	Context& mContext;
};


}  // namespace Kernel
}  // namespace PUMA