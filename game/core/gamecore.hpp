#pragma once
#include "gameclock.hpp"

class GameCore
{
public:
    // Modify constructor to take a const reference to GameClock
    GameCore(int gameID, bool gameDebug, GameClock& gameClock); // Constructor

    ~GameCore(); // Destructor
    //GameCore gameCore;

    void init();
    bool gameRunning;
    // MyEntity player;
    // MyEntity enemy;

private:
    int game_ID;
    bool game_Debug;
    GameClock& game_Clock;  // Store the GameClock as a reference
};
