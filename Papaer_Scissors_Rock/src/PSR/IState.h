#pragma once
class IState
{
public:
	IState();
	virtual ~IState();

	virtual void Entry() = 0;
	virtual void Exit() = 0;
};

