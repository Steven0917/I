#pragma once
#include "i_player.h"

namespace Game {
namespace PSR {

class HumanPlayer : public IPlayer
{
public:
	HumanPlayer();
	virtual ~HumanPlayer();

	virtual void StartGame();
	virtual void Shoot();
};


}  // namespace PSR
}  // namespace Game
