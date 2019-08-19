#pragma once
#include "IdleState.h"
#include "ShootState.h"
#include "EndGameState.h"
#include <vector>
#include <memory>

using namespace std;

class CheckStartCmd;
class CheckShootCmd;
class IPlayer;
class Game
{
public:
	Game();
	~Game();

	void StartGame();
	void CheckStart();
	void Shoot();
	void CheckShoot();
	void ClearShoot();
	void EndGame();


protected:
	int mTotalRound;
	int mCountRound;

	IState*    mpState;
	IdleState  mIdleState;
	ShootState mShootState;
	EndGameState mEndGameState;

	void ChangeState(IState& state);

	vector<IPlayer*> mPlayers;
};

