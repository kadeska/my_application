#include "item.hpp"
#include <iostream>

namespace game {

// Constructor implementation
Item::Item(const std::string& itemName) : details(itemName) {}

// Print item details
void Item::printDetails() const {
    std::cout << "Item Name: " << details.name << std::endl;
}

} // namespace game
