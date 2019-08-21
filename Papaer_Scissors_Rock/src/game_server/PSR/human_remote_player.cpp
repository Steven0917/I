#include "human_remote_player.h"
#include <iostream>
#include <thread>

namespace Game {
namespace PSR {

HumanRemotePlayer::HumanRemotePlayer(Networker& networker) : Context(networker)
{
}

HumanRemotePlayer::~HumanRemotePlayer()
{
}

void HumanRemotePlayer::StartGame(GameEngine* game, int id)
{
    IPlayer::StartGame(game, id);
	mMsgSender.SendStartGameReq();
}

void HumanRemotePlayer::Shoot()
{
	mMsgSender.SendShootReq();
}

void HumanRemotePlayer::EndGame()
{
	mMsgSender.SendEndGameReq();
}

void HumanRemotePlayer::UpdateRound(int round, int total, Shot shots[2], RoundResult result, GameScore & score)
{
    //TODO:
}

void HumanRemotePlayer::NotifyGame(int round, int total, int self_score, int counterpart_score)
{
    //TODO:
}

void HumanRemotePlayer::OnStartGame()
{
	mStarted = true;
	ExecuteCommand();
}

void HumanRemotePlayer::OnShoot(Shot shot)
{
	mShot = shot;
	ExecuteCommand();
}

void HumanRemotePlayer::OnEndGame()
{
    ExecuteCommand();
}

}  // namespace PSR
}  // namespace Game
