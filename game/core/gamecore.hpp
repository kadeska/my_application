#pragma once
#include "gameclock.hpp"

class GameCore
{
public:
    // Modify constructor to take a const reference to GameClock
    GameCore(int gameID, bool gameDebug, const GameClock& gameClock); // Constructor

    ~GameCore(); // Destructor

    void init();

private:
    int game_ID;
    bool game_Debug;
    const GameClock& game_Clock;  // Store the GameClock as a reference
};
