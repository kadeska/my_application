#include "player.hpp"
#include <iostream>
#include <string>

namespace BaseEntity {

Player::Player() {
    // Access the inherited `name` member from MyEntity
    name = "PlayerName"; // Example assignment
    std::cout << "Player created with name: " << name << std::endl;
}

}
