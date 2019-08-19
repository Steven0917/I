#include "ComputerPlayer.h"



ComputerPlayer::ComputerPlayer()
{
}


ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::StartGame()
{
	mStarted = true;
	ExecuteCommand();
}

void ComputerPlayer::Shoot()
{
	mShot = static_cast<Shot>(rand() % Shot::Unknown);
	ExecuteCommand();
}
