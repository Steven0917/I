#pragma once

#include <map>
#include <string>
#include "message.pb.h"

namespace PUMA {
namespace Kernel {

class MessageTypes
{
public:
    static std::string GetType(MSG type);
};

}  // namespace Kernel
}  // namespace PUMA