#include "client.h"
#include "context.h"
#include "network_handler.h"
#include "message.pb.h"
#include "message_handler.h"
#include "glog/logging.h"
#include <google/protobuf/message.h>

namespace PUMA {
namespace Kernel {

Client::Client(void) : mStop(true)
{
}

Client::~Client(void)
{
    // shut down worker thread
    mStop = true;

    // shut down and close the networker (listening socket)
	mNetworker.ShutDown();

    // clean up any resources left
    Networker::CleanUp();

    LOG(INFO) << "Client Terminated.";
}

bool Client::Start(void)
{
	if (mNetworker.InitClient() != NW_OK)
    {
        LOG(ERROR) << "Failed to establish connection to server.";
        return false;
    }

	mStop = false;
	return true;
}

void Client::Run(void)
{
	unique_ptr<NetworkHandler> handler(new NetworkHandler(mNetworker));
	mpHandler = move(handler);
    while (!mStop && mpHandler)
    {
		shared_ptr<Message> msg = mpHandler->RecvMsg();
		if (msg)
		{
			MessageHandler::Execute(*msg.get(), *this);
		}
    }
}


}  // namespace Kernel
}  // namespace PUMA
