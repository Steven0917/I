#pragma once

namespace Game {
namespace PSR {

enum Shot { Paper, Scissors, Rock, Unknown, Invalid };
enum RoundResult { P1_Win, P1_Lose, Try_Again };

inline const char* ToString(Shot s)
{
	switch (s)
	{
	case Paper:    return "Paper";
	case Scissors: return "Scissors";
	case Rock:     return "Rock";
	case Unknown:  return "Unknown";
	case Invalid:  return "Invalid";

	default:      return "Invalid";
	}
}

}  // namespace PSR
}  // namespace Game
