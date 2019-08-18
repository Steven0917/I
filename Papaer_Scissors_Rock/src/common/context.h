#pragma once

#include "message.pb.h"
#include "network_handler.h"
#include <memory>

namespace PUMA {
namespace Kernel {

class Context
{
public:
	Context();
	Context(Networker& networker);

    virtual ~Context();
    virtual void Process();

//protected:
	unique_ptr<NetworkHandler> mpHandler;
};

}  // namespace Kernel
}  // namespace PUMA