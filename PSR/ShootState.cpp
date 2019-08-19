#include "ShootState.h"
#include "Game.h"

ShootState::ShootState(Game& game) : IState(game)
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
