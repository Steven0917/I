#include "score.h"

namespace Game {
namespace PSR {

Score::Score() : mWin(0), mLose(0)
{
}


Score::~Score()
{
}

string Score::To_String()
{
	return to_string(mWin).append(" : ").append(to_string(mLose));
}

}  // namespace PSR
}  // namespace Game
