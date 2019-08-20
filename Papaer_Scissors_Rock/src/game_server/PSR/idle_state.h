#pragma once
#include "i_state.h"

namespace Game {
namespace PSR {

class IdleState : public IState
{
public:
	IdleState(GameEngine& game);
	virtual ~IdleState();

	virtual void Entry();
	virtual void Exit();
	
	virtual string ToString();
};


}  // namespace PSR
}  // namespace Game
