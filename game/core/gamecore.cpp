#include "gamecore.hpp"
#include "../../helper.hpp"

#include <iostream>
#include <string>


//variables

//bool gameRunning;

//functions

GameCore::GameCore(int gameID, bool gameDebug, GameClock* gameClock)
    : game_ID(gameID), game_Debug(gameDebug), game_Clock(gameClock) {
    // Initialization logic
    // std::cout << "GameCore constructor \n";
    helper.log(3, "GameCore(int gameID, bool gameDebug, GameClock* gameClock)");
    //gameCore = this;
}
GameCore::~GameCore() {}

/* This is where we start initialization of the game.
 *
  */
void GameCore::init() {
    helper.log(3, "Init game!! . . . ");
    // std::cout << "Game ID: " << game_ID << '\n';
    helper.string = std::string("Game ID: ") + std::to_string(game_ID);
    helper.log(3, helper.string);
    // std::cout << "Game Debug: " << game_Debug << '\n';
    helper.string = std::string("Game Debug: ") + std::to_string(game_Debug);
    helper.log(3, helper.string);

    gameRunning = true;


    if (!game_Clock->isRunning()) {
        // std::cout << "gameClock is not running!!... \n";
        helper.log(3, "GameClock is not running!");
        //std::cout << "Starting gameClock... \n";
        helper.log(3, "Starting GameClock . . . ");
        game_Clock->start();  // Start the clock
    } else {
        // std::cout << "gameClock is already running... \n";
        helper.log(2, "Warning... GameClock is already running. What happened??");
    }

    if (!gameRunning) {
        // std::cout << "gameRunning is false \n";
        helper.log(3, "Bool GameRunning is false");
        //std::cout << "Setting gameRunning to true \n";
        helper.log(3, "Setting Bool GameRunning to true because game is now running.");
        gameRunning = true;  // Set gameRunning to true
    }
}

void GameCore::stop(){
    if(!gameRunning){
        // std::cout << "Stopping game clock \n";
        helper.log(3, "Stopping GameClock . . . ");
        game_Clock->stop();
    }
}

