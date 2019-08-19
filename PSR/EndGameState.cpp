#include "EndGameState.h"
#include "Game.h"

EndGameState::EndGameState(Game& game) : IState(game)
{
}

EndGameState::~EndGameState()
{
}

void EndGameState::Entry()
{
	mGame.EndGame();
}

void EndGameState::Exit()
{
}

string EndGameState::ToString()
{
	return "EndGameState";
}
