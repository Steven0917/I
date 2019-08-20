#include "computer_player.h"

namespace Game {
namespace PSR {

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

void ComputerPlayer::EndGame()
{
	//Nothing need to do for computer user.
	ExecuteCommand();
}

}  // namespace PSR
}  // namespace Game
