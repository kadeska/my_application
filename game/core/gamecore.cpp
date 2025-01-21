#include "gamecore.hpp"

#include <iostream>
#include <string>


//variables

bool gameRunning;

//functions

GameCore::GameCore(int gameID, bool gameDebug, GameClock& gameClock)
    : game_ID(gameID), game_Debug(gameDebug), game_Clock(gameClock) {
    // Initialization logic
    std::cout << "GameCore constructor \n";
    //gameCore = this;
}
GameCore::~GameCore() {}

/* This is where we start initialization of the game.
 *
  */
void GameCore::init() {
    std::cout << "Game ID: " << game_ID << '\n';
    std::cout << "Game Debug: " << game_Debug << '\n';

    std::cout << "init game!!..." << '\n';

    //gameClock = new GameClock();
    //GameCore gamecore(1, true, *gameClock);
    //gameClock->start();
    //gamecore.init();

    if(!game_Clock.isRunning){
        std::cout << "gameClock is not running!!... \n";
        std::cout << "Starting gameClock... \n";
        // start gameClock
        game_Clock.start();
    }

    if(!gameRunning) {
        std::cout << "gameRunning is false \n";
        // set game rnning to true
        std::cout << "Setting gameRunning to true \n";
        gameRunning = true;
    }

}

