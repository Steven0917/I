#pragma once

namespace Game {
namespace PSR {

class GameEngine;
class GameState
{
public:
	GameState(GameEngine& game);
	virtual ~GameState();

    virtual void OnStart() = 0;
    virtual void OnPlay() = 0;
    virtual void OnUpdateScore() = 0;
    virtual void OnRestart() = 0;

    virtual void EntryState() = 0;
    virtual void ExitState() = 0;

    GameEngine& mGame;
};

}  // namespace PSR
}  // namespace Game

