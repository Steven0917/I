#pragma once

#include <string>

using namespace std;

namespace Game {
namespace PSR {

class Score
{
public:
	Score();
	~Score();

	int mWin;
	int mLose;

	string To_String();
};


}  // namespace PSR
}  // namespace Game
