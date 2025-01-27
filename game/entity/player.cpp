#include "player.hpp"
#include <iostream>
#include <string>

namespace BaseEntity {

Player::Player() : MyEntity("PlayerName") {
    std::cout << "Player created with name: " << name << std::endl;
}


}
