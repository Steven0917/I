#pragma once

#include "context.h"
#include "networker.h"
#include "start_game_req_handler.h"

using namespace std;

namespace Game {
namespace PSR {

class Client : public Context
{
    
public:
    Client(void);
    ~Client(void);
    bool Start();
    void Run();

protected:
    bool       mStop;
	Networker  mNetworker;

	StartGameRequestHandler mStartGameRequestHandler;
};


}  // namespace PSR
}  // namespace Game
