#include "Game.h"
#include "IPlayer.h"
#include "CheckStartCmd.h"
#include "CheckShootCmd.h"
#include "ComputerPlayer.h"
#include <iostream>

Game::Game() : mIdleState(*this), mShootState(*this), mEndGameState(*this), mpState(&mIdleState), mTotalRound(3)
{
	IPlayer* player1 = new ComputerPlayer();
	IPlayer* player2 = new ComputerPlayer();
	mPlayers.push_back(player1);
	mPlayers.push_back(player2);
}

Game::~Game()
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

void Game::StartGame()
{
	for (auto p : mPlayers)
	{
		p->SetCommand(new CheckStartCmd(*this));
		p->StartGame();
	}
}

void Game::CheckStart()
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

void Game::Shoot()
{
	for (auto p : mPlayers)
	{
		p->SetCommand(new CheckShootCmd(*this));
		p->Shoot();
	}
}

void Game::CheckShoot()
{
	Shot shot1 = mPlayers.at(0)->CheckShoot();
	Shot shot2 = mPlayers.at(1)->CheckShoot();

	if (Unknown == shot1 || Unknown == shot2)
	{
		return;
	}

	if (shot1 == shot2)
	{
		if (mCountRound < mTotalRound)
		{
			ChangeState(mShootState);
		}
	}

	/* Judge the round. 
	   Update date score for players
	   */
	switch (shot1)
	{
	case Paper:
		switch (shot2)
		{
		case Scissors:
			mPlayers.at(0)->LoseRound();
			mPlayers.at(1)->WinRound();
			mCountRound++;
			break;

		case Rock:
			mPlayers.at(0)->WinRound();
			mPlayers.at(1)->LoseRound();
			mCountRound++;
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
			mPlayers.at(0)->WinRound();
			mPlayers.at(1)->LoseRound();
			mCountRound++;
			break;

		case Rock:
			mPlayers.at(0)->LoseRound();
			mPlayers.at(1)->WinRound();
			mCountRound++;
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
			mPlayers.at(0)->LoseRound();
			mPlayers.at(1)->WinRound();
			mCountRound++;
			break;

		case Scissors:
			mPlayers.at(0)->WinRound();
			mPlayers.at(1)->LoseRound();
			mCountRound++;
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

	cout << "Round " << mCountRound << " / " << mTotalRound << endl;
	cout << shot1 << " : " << shot2 << endl;
	cout << "Score " << mPlayers.at(0)->GetScore().To_String() << endl << endl;


	if (mCountRound < mTotalRound)
	{
		ChangeState(mShootState);
	}
	else if (mCountRound == mTotalRound)
	{
		//ChangeState(mEndGameState);
	}
}

void Game::ClearShoot()
{
	for (auto p : mPlayers)
	{
		p->ClearShoot();
	}
}

void Game::EndGame()
{

}


void Game::ChangeState(IState & state)
{
	cout << "Change Status from " << mpState->ToString() << " to " << state.ToString() << endl;
	mpState->Exit();
	mpState = &state;
	mpState->Entry();
}
