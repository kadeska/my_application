#include "gamecore.hpp"

#include <iostream>
#include <string>


//variables

//bool gameRunning;

//functions

GameCore::GameCore(int gameID, bool gameDebug, GameClock* gameClock)
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

    gameRunning = true;


    if (!game_Clock->isRunning()) {
        std::cout << "gameClock is not running!!... \n";
        std::cout << "Starting gameClock... \n";
        game_Clock->start();  // Start the clock
    } else {
        std::cout << "gameClock is already running... \n";
    }

    if (!gameRunning) {
        std::cout << "gameRunning is false \n";
        gameRunning = true;  // Set gameRunning to true
        std::cout << "Setting gameRunning to true \n";
    }
}

void GameCore::stop(){
    if(!gameRunning){
        std::cout << "Stopping game clock \n";
        game_Clock->stop();
    }
}

