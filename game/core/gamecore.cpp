#include "gamecore.hpp"
#include <iostream>
#include <string>


//variables


//functions

GameCore::GameCore(int gameID, bool gameDebug) {
    game_ID = gameID;
    game_Debug = gameDebug;

}
GameCore::~GameCore() {}

void GameCore::init() {
    std::cout << "Game ID: " << game_ID << '\n';
    std::cout << "Game Debug: " << game_Debug << '\n';
}
