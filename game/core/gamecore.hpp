#pragma once

class GameCore
{
public:
    GameCore(int gameID, bool gameDebug); //constructor takes int ID, bool debug
    ~GameCore(); //destructor

    void init();

private:
    int game_ID;
    bool game_Debug;
};
