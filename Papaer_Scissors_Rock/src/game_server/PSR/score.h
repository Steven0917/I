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

class GameScore
{
public:
    GameScore();
    ~GameScore();

    int _score[2];

    bool GetScore(int player_id, int& self_score, int& counterpart_score);
};

}  // namespace PSR
}  // namespace Game
