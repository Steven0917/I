#pragma once
#include "game_state.h"

namespace Game {
namespace PSR {

class IdleState :  public GameState
{
public:
    IdleState();
    virtual ~IdleState();

    virtual void OnStart() {};
    virtual void OnPlay() {};
    virtual void OnUpdateScore() {};
    virtual void OnRestart() {};
};

}  // namespace PSR
}  // namespace Game

