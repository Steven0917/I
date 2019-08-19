#pragma once

#include <string>

#define MAINVER 2
#define SUBVER1 2
#define SUBVER2 13

#define V_STR(s)     #s 
#define GET_GAME_PSR_VERSION(a,b,c)  "v" V_STR(a) "." V_STR(b) "." V_STR(c)
#define GET_GAME_PSR_BUILD(a,b,c)    "v" V_STR(a) "." V_STR(b) "." V_STR(c) " "__DATE__" " __TIME__

namespace Game {
namespace PSR {

const std::string GAME_PSR_VERSION = GET_GAME_PSR_VERSION(MAINVER, SUBVER1, SUBVER2);
const std::string GAME_PSR_BUILD   = GET_GAME_PSR_BUILD(MAINVER, SUBVER1, SUBVER2);


}
}
