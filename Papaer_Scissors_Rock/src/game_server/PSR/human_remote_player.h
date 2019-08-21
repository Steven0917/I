#pragma once
#include "i_player.h"
#include "context.h"
#include "networker.h"
#include "context.h"
#include "start_game_rsp_handler.h"

namespace Game {
namespace PSR {

class HumanRemotePlayer : public IPlayer, public Context
{
public:
	HumanRemotePlayer(Networker& networker);
	virtual ~HumanRemotePlayer();

	virtual void StartGame(GameEngine* game, int id);
	virtual void Shoot();
	virtual void EndGame();
    virtual void UpdateRound(int round, int total, Shot shots[2],
        RoundResult result, GameScore& score);
    virtual void NotifyGame(int round, int total, int self_score, int counterpart_score);

	void OnStartGame();
	void OnShoot(Shot shot);
    void OnEndGame();

protected:
	StartGameResponseHandler mStartGameResponseHandler;
};


}  // namespace PSR
}  // namespace Game
