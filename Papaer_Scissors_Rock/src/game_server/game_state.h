#pragma once

namespace Game {
namespace PSR {

class GameState
{
public:
	GameState();
	virtual ~GameState();

    virtual void OnStart() = 0;
    virtual void OnPlay() = 0;
    virtual void OnUpdateScore() = 0;
    virtual void OnRestart() = 0;
};

}  // namespace PSR
}  // namespace Game

