#pragma once

#include "context.h"
#include "networker.h"
#include "thread_pool.h"
#include "reg_rsp_handler.h"

using namespace std;

namespace PUMA {
namespace Kernel {

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

	RegisterResponseHandler mRegRspHandler;

};


}  // namespace Kernel
}  // namespace PUMA
