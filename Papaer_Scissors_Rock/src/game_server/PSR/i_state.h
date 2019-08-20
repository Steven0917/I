#pragma once
#include <string>

using namespace std;

namespace Game {
namespace PSR {

class GameEngine;
class IState
{
public:
	IState(GameEngine& game);
	virtual ~IState();

	virtual void Entry() = 0;
	virtual void Exit() = 0;

	virtual string ToString();
protected:
    GameEngine& mGame;
};


}  // namespace PSR
}  // namespace Game
