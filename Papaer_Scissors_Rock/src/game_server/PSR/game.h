#pragma once

#include "idle_state.h"
#include "shoot_state.h"
#include "end_game_state.h"
#include "networker.h"
#include <vector>

using namespace std;

namespace Game {
namespace PSR {

class CheckStartCmd;
class CheckShootCmd;
class IPlayer;
class GameEngine
{
public:
    GameEngine(Networker& networker);
	~GameEngine();

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


}  // namespace PSR
}  // namespace Game
