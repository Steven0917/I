#include "end_game_state.h"
#include "game.h"

namespace Game {
namespace PSR {

EndGameState::EndGameState(GameEngine& game) : IState(game)
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

}  // namespace PSR
}  // namespace Game
