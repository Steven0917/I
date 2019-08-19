#pragma once

#include "context.h"
#include "networker.h"
#include "thread_pool.h"

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


private:
    bool   mStop;
	Networker  mNetworker;

};


}  // namespace PSR
}  // namespace Game
