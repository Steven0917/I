#pragma once

#include "i_state.h"

namespace Game {
namespace PSR {

class EndGameState : public IState
{
public:
	EndGameState(GameEngine& game);
	virtual ~EndGameState();

	virtual void Entry();
	virtual void Exit();

	virtual string ToString();
};


}  // namespace PSR
}  // namespace Game
