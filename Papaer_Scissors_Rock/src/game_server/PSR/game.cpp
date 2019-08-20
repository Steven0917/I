#include "game.h"
#include "i_player.h"
#include "check_start_cmd.h"
#include "check_shoot_cmd.h"
#include "computer_player.h"
#include "human_player.h"
#include <iostream>

namespace Game {
namespace PSR {

GameEngine::GameEngine() : mIdleState(*this), mShootState(*this), mEndGameState(*this), mpState(&mIdleState), mTotalRound(3)
{
	IPlayer* player1 = new HumanPlayer();
	IPlayer* player2 = new ComputerPlayer();
	mPlayers.push_back(player1);
	mPlayers.push_back(player2);
}

GameEngine::~GameEngine()
{
	for (auto p : mPlayers)
	{
		if (p)
		{
			delete p;
		}
	}
	mPlayers.clear();
}

void GameEngine::StartGame()
{
	for (auto p : mPlayers)
	{
		p->SetCommand(new CheckStartCmd(*this));
		p->StartGame();
	}
}

void GameEngine::CheckStart()
{
	for (auto p : mPlayers)
	{
		if (false == p->CheckStart())
		{
			return;
		}
	}

	ChangeState(mShootState);
}

void GameEngine::Shoot()
{
	cout << "Round " << mCountRound + 1 << " / " << mTotalRound << endl;
	for (auto p : mPlayers)
	{
		p->SetCommand(new CheckShootCmd(*this));
		p->Shoot();
	}
}

void GameEngine::CheckShoot()
{
	Shot shot1 = mPlayers.at(0)->CheckShoot();
	Shot shot2 = mPlayers.at(1)->CheckShoot();

	if (Unknown == shot1 || Unknown == shot2)
	{
		return;
	}

	if (Invalid == shot1 || Invalid == shot2)
	{
		cout << "Invalid shot." << endl << endl;
		ChangeState(mShootState);
		return;
	}

	if (shot1 == shot2)
	{
		cout << endl << ToString(shot1) << " = " << ToString(shot2) << endl;

		cout << "Score " << mPlayers.at(0)->GetScore().To_String()
			 << "    [Round " << mCountRound + 1 << " / " << mTotalRound << "]" << endl << endl;

		if (mCountRound < mTotalRound)
		{
			ChangeState(mShootState);
            return;
		}
	}

	/* Judge this round. 
	   Update date score for players
	   */
	bool isP1Win;
	switch (shot1)
	{
	case Paper:
		switch (shot2)
		{
		case Scissors:
			isP1Win = false;
			break;

		case Rock:
			isP1Win = true;
			break;

		case Paper:
		case Unknown:
		default:
			cout << "Error: " << shot1 << " : " << shot2 << endl;
			break;
		}
		break;

	case Scissors:
		switch (shot2)
		{
		case Paper:
			isP1Win = true;
			break;

		case Rock:
			isP1Win = false;
			break;

		case Scissors:
		case Unknown:
		default:
			cout << "Error: " << shot1 << " : " << shot2 << endl;
			break;
		}
		break;

	case Rock:
		switch (shot2)
		{
		case Paper:
			isP1Win = false;
			break;

		case Scissors:
			isP1Win = true;
			break;

		case Rock:
		case Unknown:
		default:
			cout << "Error: " << shot1 << " : " << shot2 << endl;
			break;
		}
		break;

	default:
		cout << "Error: " << shot1 << " : " << shot2 << endl;
		break;
	}

	if (isP1Win)
	{
		mPlayers.at(0)->WinRound();
		mPlayers.at(1)->LoseRound();
		mCountRound++;
	}
	else
	{
		mPlayers.at(0)->LoseRound();
		mPlayers.at(1)->WinRound();
		mCountRound++;
	}

	cout << endl << ToString(shot1) << (isP1Win ? " <<<<<< " : " >>>>>> ") << ToString(shot2) << endl;

	cout << "Score " << mPlayers.at(0)->GetScore().To_String()
		<< "    [Round " << mCountRound << " / " << mTotalRound << "]" << endl << endl;

	if (mCountRound < mTotalRound)
	{
		ChangeState(mShootState);
	}
	else if (mCountRound == mTotalRound)
	{
		ChangeState(mEndGameState);
	}
}

void GameEngine::ClearShoot()
{
	for (auto p : mPlayers)
	{
		p->ClearShoot();
	}
}

void GameEngine::EndGame()
{
	for (auto p : mPlayers)
	{
		p->SetCommand(nullptr);
		p->EndGame();
	}
}

void GameEngine::ChangeState(IState & state)
{
	//cout << "Change Status from " << mpState->ToString() << " to " << state.ToString() << endl;
	mpState->Exit();
	mpState = &state;
	mpState->Entry();
}

}  // namespace PSR
}  // namespace Game
