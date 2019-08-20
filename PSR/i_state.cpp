#include "i_state.h"

namespace Game {
namespace PSR {

IState::IState(GameEngine& game) : mGame(game)
{
}

IState::~IState()
{
}

string IState::ToString()
{
	return "IState";
}

}  // namespace PSR
}  // namespace Game
