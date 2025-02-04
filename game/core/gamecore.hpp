#pragma once


#include "../../glWindow/glWindowCore/openglwindow.hpp"
#include "gameclock.hpp"

/**
 * @brief The GameCore class
 * This class is for core funcionality of the game,
 * core machanics like game clock, maintaining game state,
 * maintaining core features like inventories and Player and
 * entities, and anything else that is a core function for a game.
 *
 * This class should not contain any custom or spacific funcionality,
 * except for core game functionality. Anything that is not related to
 * core game aspects should be its own managment class. This class will
 * have functions to referance the differant managers.
 *
 *
 * things this class should contain:
 * - GameClock // As a referance to GameClock class
 * - GameSoundManager // As a referance to GameSoundManager class
 */
class GameCore
{
public:
    GameCore(int gameID, bool gameDebug, GameClock* gameClock, OpenglWindow* window);
    ~GameCore();

    /**
     * @brief init
     * Initialize the game
     */
    void init();
    /**
     * @brief stop
     * Stop the game
     */
    void stop();

    GameClock* game_Clock;
    bool gameRunning;


    //static void stop();

    bool getGameRunning() const;
    void setGameRunning(bool newGameRunning);

private:
    int game_ID;
    bool game_Debug;
};
