#pragma once

#include "message.pb.h"
#include <memory>

using std::shared_ptr;

namespace Game {
namespace PSR {

class Networker;
class MessageSender
{
public:

    MessageSender();
    MessageSender(Networker& networker);
    void SetNetworker(Networker& networker);
    virtual ~MessageSender();

    void SendStartGameReq();
    void SendStartGameRsp();
    void SendShootReq();
    void SendShootRsp(SHOT_TYPE shot);
    void SendEndGameReq();
    void SendEndGameRsp();

    void SendRoundNotification(int round, int total,
        SHOT_TYPE self, SHOT_TYPE counterpart, ROUND_RESULT_TYPE result);

private:
    void SendRequest(Request* req, MSG type);
    void SendResponse(Response* rsp, MSG type);
    void SendNotification(Notification* notify, MSG type);

    void SendMsg(shared_ptr<Message>& msg);

private:
    Networker mNetworker;
};


}  // namespace PSR
}  // namespace Game
