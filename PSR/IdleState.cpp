#include "IdleState.h"
#include "Game.h"

IdleState::IdleState(Game& game) : IState(game)
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
