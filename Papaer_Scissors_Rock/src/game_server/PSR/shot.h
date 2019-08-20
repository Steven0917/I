#pragma once

namespace Game {
namespace PSR {

enum Shot { Paper, Scissors, Rock, Unknown, Invalid };

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
