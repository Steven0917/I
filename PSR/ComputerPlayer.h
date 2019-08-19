#pragma once
#include "IPlayer.h"

class ComputerPlayer : public IPlayer
{
public:
	ComputerPlayer();
	virtual ~ComputerPlayer();

	virtual void StartGame();
	virtual void Shoot();
};

