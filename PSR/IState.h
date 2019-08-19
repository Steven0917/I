#pragma once
#include <string>

using namespace std;

class Game;
class IState
{
public:
	IState(Game& game);
	virtual ~IState();

	virtual void Entry() = 0;
	virtual void Exit() = 0;

	virtual string ToString();
protected:
	Game& mGame;
};

