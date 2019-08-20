#include "i_player.h"

namespace Game {
namespace PSR {

IPlayer::IPlayer() : mShot(Shot::Unknown), mCmd(nullptr)
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
