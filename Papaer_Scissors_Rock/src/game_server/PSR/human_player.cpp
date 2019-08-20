#include "human_player.h"
#include <iostream>
#include <thread>

namespace Game {
namespace PSR {

HumanPlayer::HumanPlayer(Networker& networker) : Context(networker)
{
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::StartGame()
{
#if 0
	cout << "**********************************************" << endl
		 << "Welcome to Paper Scissors Rock Game!" << endl << endl
		 << "You will play the game with computer. Rules:" << endl << endl
		 << "1. Choose your shots in total 3 rounds:" << endl
		 << "    P -> Paper, S -> Scissors, R -> Rock" << endl << endl
		 << "2. Paper wraps Rock," << endl
		 << "   Rock blunts Scissors," << endl
		 << "   Sissors cuts Paper." << endl << endl
		 << "**********************************************" << endl << endl;

	cout << "Press Enter to start the game.";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "Game Started!" << endl << endl << endl;
	mStarted = true;
	ExecuteCommand();
#else
	mMsgSender.SendStartGameReq();
#endif
}

void HumanPlayer::Shoot()
{
#if 0
	cout << "Please Shoot [P, S, R]: ";
	char c;
	cin >> c;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

	switch (c)
	{
	case 'P':
	case 'p':
		mShot = Shot::Paper;
		break;
	case 'S':
	case 's':
		mShot = Shot::Scissors;
		break;
	case 'R':
	case 'r':
		mShot = Shot::Rock;
		break;
	default:
		mShot = Shot::Invalid;
		break;
	}

	ExecuteCommand();
#else
	mMsgSender.SendShootReq();
#endif
}

void HumanPlayer::EndGame()
{
#if 0
	this_thread::sleep_for(1s);

	cout << endl;
	cout << "***************************" << endl
		 << "Paper Scissors Rock Game!" << endl << endl
		 << "YOU " << (mScore.mWin > mScore.mLose ? "WIN!" : "LOSE!") << endl
		 << "Final score is " << mScore.To_String() << endl
		 << "***************************" << endl << endl;
	
	this_thread::sleep_for(2s);

	cout << endl << endl << endl
		 << "Thanks for playing with us. Press Enter to exit the game." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

	ExecuteCommand();
#else
	mMsgSender.SendEndGameReq();
#endif
}

void HumanPlayer::OnStartGame()
{
	mStarted = true;
	ExecuteCommand();
}

void HumanPlayer::OnShoot(Shot shot)
{
	mShot = shot;
	ExecuteCommand();
}

}  // namespace PSR
}  // namespace Game
