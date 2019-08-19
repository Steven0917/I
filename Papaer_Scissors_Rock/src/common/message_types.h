#pragma once

#include <map>
#include <string>
#include "message.pb.h"

namespace Game {
namespace PSR {

class MessageTypes
{
public:
    static std::string GetType(MSG type);
};

}  // namespace PSR
}  // namespace Game
