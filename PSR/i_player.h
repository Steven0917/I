#pragma once
#include "shot.h"
#include "score.h"
#include "command.h"
#include <memory>

using namespace std;

namespace Game {
namespace PSR {

class IPlayer
{
public:
	IPlayer();
	virtual ~IPlayer();

	virtual void StartGame() {};
	virtual void Shoot() {};
	virtual void EndGame() {};

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


}  // namespace PSR
}  // namespace Game
