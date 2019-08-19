#include "message_types.h"


namespace Game {
namespace PSR {

std::map<MSG, std::string> MSG_TYPE = {
    { unknown_message, "unknown_message" }
};

std::string MessageTypes::GetType(MSG type)
{
    return MSG_TYPE[type];
}

}  // namespace PSR
}  // namespace Game
