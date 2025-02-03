#include "item.hpp"
#include "../../helper.hpp"
#include <iostream>

namespace game {

// Constructor implementation
Item::Item(const std::string& itemName, int ID) : details(itemName, ID) {}

// Print item details
void Item::printDetails() const {
    std::cout << "Item Name: " << details.name << std::endl;
    helper.log(3, std::string("Item ID: " + std::to_string(details.ID)));
}

} // namespace game
