#include "message_types.h"


namespace PUMA {
namespace Kernel {

std::map<MSG, std::string> MSG_TYPE = {
    { unknown_message, "unknown_message" },
    { Register_Request, "Register_Request" },
    { Register_Response, "Register_Response" }
};

std::string MessageTypes::GetType(MSG type)
{
    return MSG_TYPE[type];
}

}  // namespace Kernel
}  // namespace PUMA