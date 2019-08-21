#pragma once
#include "i_player.h"

namespace Game {
namespace PSR {

class ComputerPlayer : public IPlayer
{
public:
	ComputerPlayer();
	virtual ~ComputerPlayer();

	virtual void StartGame(GameEngine* game, int id);
	virtual void Shoot();
	virtual void EndGame();
    virtual void UpdateRound(int round, int total, Shot shots[2],
        RoundResult result, GameScore& score);
};


}  // namespace PSR
}  // namespace Game
