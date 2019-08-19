#pragma once
#include "Shot.h"
#include "Score.h"
#include "Command.h"
#include <memory>

using namespace std;
class IPlayer
{
public:
	IPlayer();
	virtual ~IPlayer();

	virtual void StartGame() {};
	virtual void Shoot() {};
	bool CheckStart();
	Shot CheckShoot();
	void ClearShoot();

	void WinRound();
	void LoseRound();

	Score GetScore();
	void SetCommand(Command* cmd);

	void ExecuteCommand();

protected:
	bool mStarted;
	Shot mShot;
	Score mScore;

	Command* mCmd;
};

