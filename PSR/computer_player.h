#pragma once
#include "i_player.h"

namespace Game {
namespace PSR {

class ComputerPlayer : public IPlayer
{
public:
	ComputerPlayer();
	virtual ~ComputerPlayer();

	virtual void StartGame();
	virtual void Shoot();
};


}  // namespace PSR
}  // namespace Game
