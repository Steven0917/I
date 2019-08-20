#include "idle_state.h"
#include "game.h"

namespace Game {
namespace PSR {

IdleState::IdleState(GameEngine& game) : IState(game)
{
}

IdleState::~IdleState()
{
}

void IdleState::Entry()
{
	mGame.StartGame();
}

void IdleState::Exit()
{
}

string IdleState::ToString()
{
	return "IdleState";
}

}  // namespace PSR
}  // namespace Game
