#pragma once


#include "../../glWindow/glWindowCore/openglwindow.hpp"
#include "gameclock.hpp"

class GameCore
{
public:
    GameCore(int gameID, bool gameDebug, GameClock* gameClock, OpenglWindow* window);
    ~GameCore();

    void init();
    void stop();

    GameClock* game_Clock;
    bool gameRunning;

    //static void stop();

private:
    int game_ID;
    bool game_Debug;
};
