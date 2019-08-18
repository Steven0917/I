#include "context.h"
#include "message_handler.h"
#include "glog\logging.h"

namespace PUMA {
namespace Kernel {

Context::Context()
{
}

Context::Context(Networker & networker) : mpHandler(new NetworkHandler(networker))
{
}

Context::~Context()
{
    LOG(INFO) << "Client::~Client()";
}

void Context::Process()
{
}

}  // namespace Kernel
}  // namespace PUMA