#include "gamecore.hpp"
#include <iostream>
#include <string>


//variables


//functions

GameCore::GameCore(int gameID, bool gameDebug, const GameClock& gameClock)
    : game_ID(gameID), game_Debug(gameDebug), game_Clock(gameClock) {
    // Initialization logic
}
GameCore::~GameCore() {}

void GameCore::init() {
    std::cout << "Game ID: " << game_ID << '\n';
    std::cout << "Game Debug: " << game_Debug << '\n';
    if(!game_Clock.isRunning){
        std::cout << "gameClock is not running!!... \n";
    }

}
