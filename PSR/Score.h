#pragma once

#include <string>

using namespace std;
class Score
{
public:
	Score();
	~Score();

	int mWin;
	int mLose;

	string To_String();
};

