#include "game.h"
#include "i_player.h"
#include "check_start_cmd.h"
#include "check_shoot_cmd.h"
#include "computer_player.h"
#include "human_player.h"
#include "human_remote_player.h"
#include <iostream>

namespace Game {
namespace PSR {

GameEngine::GameEngine(Networker& networker) : mIdleState(*this), mShootState(*this), mEndGameState(*this), mpState(&mIdleState),
            mCurrentRound(1), mTotalRound(3)
{
	mPlayers.push_back(new HumanRemotePlayer(networker));
	mPlayers.push_back(new ComputerPlayer());
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
    for (int i = 0; i < mPlayers.size(); i++)
	{
        mPlayers.at(i)->SetCommand(new CheckStartCmd(*this));
        mPlayers.at(i)->StartGame(this, i);
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
	cout << "Round " << mCurrentRound + 1 << " / " << mTotalRound << endl;
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
        RoundUpdate(shot1, shot2, Try_Again);
		return;
	}

	if (Invalid == shot1 || Invalid == shot2)
	{
		cout << "Invalid shot." << endl << endl;
        RoundUpdate(shot1, shot2, Try_Again);
		ChangeState(mShootState);
		return;
	}

	if (shot1 == shot2)
	{
		cout << endl << ToString(shot1) << " = " << ToString(shot2) << endl;

		cout << "Score " << mPlayers.at(0)->GetScore().To_String()
			 << "    [Round " << mCurrentRound + 1 << " / " << mTotalRound << "]" << endl << endl;
        
        RoundUpdate(shot1, shot2, Try_Again);

		if (mCurrentRound <= mTotalRound)
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
        mScore._score[0] += 1;
		mPlayers.at(0)->WinRound();
		mPlayers.at(1)->LoseRound();
	}
	else
	{
        mScore._score[1] += 1;
        mPlayers.at(0)->LoseRound();
		mPlayers.at(1)->WinRound();
	}

	cout << endl << ToString(shot1) << (isP1Win ? " <<<<<< " : " >>>>>> ") << ToString(shot2) << endl;

	cout << "Score " << mPlayers.at(0)->GetScore().To_String()
		<< "    [Round " << mCurrentRound << " / " << mTotalRound << "]" << endl << endl;

    RoundUpdate(shot1, shot2, isP1Win? P1_Win: P1_Lose);
    mCurrentRound++;

	if (mCurrentRound <= mTotalRound)
	{
		ChangeState(mShootState);
	}
	else if (mCurrentRound > mTotalRound)
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

void GameEngine::RoundUpdate(Shot shot1, Shot shot2, RoundResult result)
{
    Shot shots[2] = { shot1, shot2 };
    for (auto p : mPlayers)
    {
        p->UpdateRound(mCurrentRound, mTotalRound, shots, result, mScore);
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
