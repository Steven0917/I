#include "shoot_state.h"
#include "game.h"

namespace Game {
namespace PSR {

ShootState::ShootState(GameEngine& game) : IState(game)
{
}

ShootState::~ShootState()
{
}

void ShootState::Entry()
{
	mGame.Shoot();
}

void ShootState::Exit()
{
	mGame.ClearShoot();
}

string ShootState::ToString()
{
	return "ShootState";
}

}  // namespace PSR
}  // namespace Game
