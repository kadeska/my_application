#include "gamecore.hpp"
#include "../../helper.hpp"
//#include "controls.hpp"
#include <iostream>
#include <string>

// Constructor
GameCore::GameCore(int gameID, bool gameDebug, GameClock* gameClock, OpenglWindow* window)
    : game_ID(gameID), game_Debug(gameDebug), game_Clock(gameClock), gameRunning(false)
{
    helper.log(3, "GameCore(int gameID, bool gameDebug, GameClock* gameClock)");
}

// Destructor
GameCore::~GameCore() {}

// Initialize the game
void GameCore::init() {
    helper.log(3, "Init game!! . . . ");
    helper.string = std::string("Game ID: ") + std::to_string(game_ID);
    helper.log(3, helper.string);

    helper.string = std::string("Game Debug: ") + std::to_string(game_Debug);
    helper.log(3, helper.string);

    //gameRunning = true;
    setGameRunning(true);
    //controls(this);


    if (!game_Clock->isRunning()) {
        helper.log(3, "GameClock is not running!");
        helper.log(3, "Starting GameClock . . . ");
        game_Clock->start();  // Start the clock
    } else {
        helper.log(2, "Warning... GameClock is already running. What happened??");
    }

    if (!getGameRunning()) {
        helper.log(3, "Bool GameRunning is false");
        helper.log(3, "Setting Bool GameRunning to true because game is now running.");
        //gameRunning = true;
        setGameRunning(true);
    }
}

// Stop the game
void GameCore::stop() {
    if (getGameRunning()) {
        helper.log(3, "Stopping GameClock . . . ");
        game_Clock->stop();
        //gameRunning = false;
        setGameRunning(false);
    }
}

bool GameCore::getGameRunning() const
{
    return gameRunning;
}

void GameCore::setGameRunning(bool newGameRunning)
{
    gameRunning = newGameRunning;
}
