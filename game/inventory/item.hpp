#pragma once
#include <string>

namespace game {

class Item {
public:
    // Constructor to initialize an item with a name
    Item(const std::string& itemName);

    // Method to print item details
    void printDetails() const;

private:
    struct ItemDetails {
        std::string name; // Name of the item

        // Constructor that accepts a name
        ItemDetails(const std::string& itemName) : name(itemName) {}
    };

    ItemDetails details; // Instance of ItemDetails
};

} // namespace game
