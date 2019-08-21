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

    virtual void StartGame(GameEngine* game, int id) { mGame = game; mId = id; };
	virtual void Shoot() {};
	virtual void EndGame() {};
    virtual void UpdateRound(int round, int total, Shot shots[2],
        RoundResult result, GameScore& score);
    virtual void NotifyGame(int round, int total, int self_score, int counterpart_score);

	bool CheckStart();
	Shot CheckShoot();
	void ClearShoot();


	void WinRound();
	void LoseRound();

	Score GetScore();
	void SetCommand(Command* cmd);

	void ExecuteCommand();

protected:
    int  mId;
    bool mStarted;
	Shot mShot;
	Score mScore;

	Command* mCmd;
    GameEngine* mGame;
};


}  // namespace PSR
}  // namespace Game
