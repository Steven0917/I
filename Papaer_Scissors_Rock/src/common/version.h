#pragma once

#include <string>

#define MAINVER 2
#define SUBVER1 2
#define SUBVER2 13

#define V_STR(s)     #s 
#define GET_PUMA_KERNEL_VERSION(a,b,c)  "v" V_STR(a) "." V_STR(b) "." V_STR(c)
#define GET_PUMA_KERNEL_BUILD(a,b,c)  "v" V_STR(a) "." V_STR(b) "." V_STR(c) " "__DATE__" " __TIME__

namespace Game {
namespace PSR {

const std::string PUMA_KERNEL_VER   = GET_PUMA_KERNEL_VERSION(MAINVER, SUBVER1, SUBVER2);
const std::string PUMA_KERNEL_BUILD = GET_PUMA_KERNEL_BUILD(MAINVER, SUBVER1, SUBVER2);


}
}
