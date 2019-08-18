#pragma once

#include <map>
#include "networker.h"
#include "thread_pool.h"

using namespace std;

namespace PUMA {
namespace Kernel {


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


}  // namespace Kernel
}  // namespace PUMA
