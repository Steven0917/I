#include "server.h"
#include "server_config.h"
#include "networker.h"
#include "game_psr.h"
#include "message.pb.h"
#include "glog/logging.h"
#include <google/protobuf/message.h>

namespace PUMA {
namespace Kernel {

class ClientConnection
{
public:
    void operator() (Networker& networker, Server& server)
    {
		GamePSR game(networker);
        game.Start();
        //superNode.Run();
    }
};

Server::Server(void) : mWorkers(ServerConfig::Instance().GetThreadPoolSize()), mStop(true)
{
}

Server::~Server(void)
{
    // shut down worker thread
    mStop = true;

    // shut down and close the networker (listening socket)
	mListener.ShutDown();

    // clean up any resources left
    Networker::CleanUp();

    LOG(INFO) << "Server Terminated.";
}

bool Server::Start(void)
{
    if (mListener.InitServer() != NW_OK)
    {
        LOG(ERROR) << "Failed to init server.";
        return false;
    }

	mStop = false;
	return true;
}

void Server::Run(void)
{
	Networker networker;
    int cnt = 0;
    while (!mStop)
    {
		networker = mListener.Accept();

        if (networker.isValid())
        {
            LOG(INFO) << "-------------------";
            LOG(INFO) << "New peer connected: " << ++cnt;

            mWorkers.enqueue(ClientConnection{}, networker, std::ref(*this));
        }
    }
}


}  // namespace Kernel
}  // namespace PUMA
