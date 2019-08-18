#pragma once
#include <memory>
#include "networker.h"
#include "message.pb.h"
#include <google/protobuf/message.h>

using namespace std;

namespace PUMA {
namespace Kernel {

class NetworkHandler
{
public:
	NetworkHandler(Networker& networker);
	virtual ~NetworkHandler();

	shared_ptr<Message> RecvMsg();
	void SendMsg(shared_ptr<Message>& msg);

//protected:
	Networker mNetworker;

};

}  // namespace Kernel
}  // namespace PUMA

