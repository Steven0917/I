#include "i_player.h"

namespace Game {
namespace PSR {

IPlayer::IPlayer() : mId(-1), mShot(Shot::Unknown), mCmd(nullptr), mGame(nullptr)
{
}

IPlayer::~IPlayer()
{
}

bool IPlayer::CheckStart()
{
	return mStarted;
}

Shot IPlayer::CheckShoot()
{
	return mShot;
}

void IPlayer::ClearShoot()
{
    mShot = Shot::Unknown;
}

void IPlayer::UpdateRound(int round, int total, Shot shots[2],
    RoundResult result, GameScore& score)
{
}

void IPlayer::NotifyGame(int round, int total, int self_score, int counterpart_score)
{
}

void IPlayer::WinRound()
{
	mScore.mWin++;
}

void IPlayer::LoseRound()
{
	mScore.mLose++;
}

Score IPlayer::GetScore()
{
	return mScore;
}

void IPlayer::SetCommand(Command* cmd)
{
	if (cmd)
	{
		mCmd = cmd;
	}
}

void IPlayer::ExecuteCommand()
{
	if (mCmd)
	{
		mCmd->Execute();
		delete mCmd;
		mCmd = nullptr;
	}
}

}  // namespace PSR
}  // namespace Game
