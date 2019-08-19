#pragma once
#include "game_state.h"

namespace Game {
namespace PSR {

class GameStartedState : public GameState
{
public:
    GameStartedState(GameEngine& game);
    virtual ~GameStartedState();

    virtual void OnStart() {};
    virtual void OnPlay() {};
    virtual void OnUpdateScore() {};
    virtual void OnRestart() {};

    virtual void EntryState() {};
    virtual void ExitState() {};
};

}  // namespace PSR
}  // namespace Game

