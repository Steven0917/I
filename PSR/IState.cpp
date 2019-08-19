#include "IState.h"

IState::IState(Game& game) : mGame(game)
{
}


IState::~IState()
{
}

string IState::ToString()
{
	return "IState";
}
