#pragma once
#include <memory>
#include "networker.h"
#include "message.pb.h"
#include <google/protobuf/message.h>

using namespace std;

namespace Game {
namespace PSR {

class NetworkHandler
{
public:
    NetworkHandler();
	NetworkHandler(Networker& networker);
	virtual ~NetworkHandler();

	shared_ptr<Message> RecvMsg();
	void SendMsg(shared_ptr<Message>& msg);

    void SetNetworker(Networker& networker);

//protected:
	Networker mNetworker;

};

}  // namespace PSR
}  // namespace Game

