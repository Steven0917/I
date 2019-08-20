#pragma once
#include "i_player.h"
#include "context.h"
#include "networker.h"
#include "context.h"
#include "start_game_rsp_handler.h"

namespace Game {
namespace PSR {

class HumanPlayer : public IPlayer, public Context
{
public:
	HumanPlayer(Networker& networker);
	virtual ~HumanPlayer();

	virtual void StartGame();
	virtual void Shoot();
	virtual void EndGame();

	void OnStartGame();
	void OnShoot(Shot shot);

protected:
	StartGameResponseHandler mStartGameResponseHandler;
};


}  // namespace PSR
}  // namespace Game
