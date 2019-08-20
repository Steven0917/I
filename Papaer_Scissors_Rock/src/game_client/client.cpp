#include "client.h"
#include "context.h"
#include "network_handler.h"
#include "message.pb.h"
#include "message_handler.h"
#include "glog/logging.h"
#include <thread>
#include <google/protobuf/message.h>

namespace Game {
namespace PSR {

Client::Client(void) : mStop(true), mNetworker()
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
	if (mNetworker.InitClient() == NW_OK)
    {
        LOG(INFO) << "Connected to server.";
        SetNetworker(mNetworker);
	    mStop = false;
	    return true;
    }

    LOG(ERROR) << "Failed to establish connection to server.";
    return false;
}

void Client::Run(void)
{
    while (!mStop)
    {
		shared_ptr<Message> msg = mMsgHandler.RecvMsg();
		if (msg)
		{
			MessageHandler::Execute(*msg.get(), *this);
		}
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}


}  // namespace PSR
}  // namespace Game
