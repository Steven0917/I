#pragma once
#include "i_state.h"

namespace Game {
namespace PSR {

class ShootState : public IState
{
public:
	ShootState(GameEngine& game);
	virtual ~ShootState();

	virtual void Entry();
	virtual void Exit();

	virtual string ToString();
};


}  // namespace PSR
}  // namespace Game
