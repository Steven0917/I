#include "computer_player.h"

namespace Game {
namespace PSR {

ComputerPlayer::ComputerPlayer()
{
}


ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::StartGame(GameEngine* game, int id)
{
	mStarted = true;
    IPlayer::StartGame(game, id);
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

void ComputerPlayer::UpdateRound(int round, int total, Shot shots[2], RoundResult result, GameScore & score)
{
}

}  // namespace PSR
}  // namespace Game
