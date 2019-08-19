#pragma once
#include "game_state.h"

namespace Game {
namespace PSR {

class IdleState : public GameState
{
public:
    IdleState(GameEngine& game);
    virtual ~IdleState();

    virtual void OnStart() {};
    virtual void OnPlay() {};
    virtual void OnUpdateScore() {};
    virtual void OnRestart() {};

    virtual void EntryState() {};
    virtual void ExitState() {};
};

}  // namespace PSR
}  // namespace Game
