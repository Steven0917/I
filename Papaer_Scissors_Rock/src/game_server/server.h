#pragma once

#include <map>
#include "networker.h"
#include "thread_pool.h"

using namespace std;

namespace Game {
namespace PSR {


class Server
{
public:
    Server(void);
    ~Server(void);
    bool Start();
    void Run();


private:
    bool   mStop;
	Networker  mListener;
	ThreadPool mWorkers;
};


}  // namespace PSR
}  // namespace Game
