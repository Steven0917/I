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

GameScore::GameScore()
{
    _score[0] = _score[1] = 0;
}

GameScore::~GameScore()
{
}

bool GameScore::GetScore(int player_id, int & self_score, int & counterpart_score)
{
    if (player_id > 1 || player_id < 0)
    {
        return false;
    }
    else
    {
        self_score = _score[player_id];
        counterpart_score = _score[1 - player_id];
        
        return true;
    }
}

}  // namespace PSR
}  // namespace Game
