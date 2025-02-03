#pragma once
#include <string>

namespace game {

class Item {
public:
    // Constructor to initialize an item with a name
    Item(const std::string& itemName, int ID);

    // Method to print item details
    void printDetails() const;

private:
    struct ItemDetails {
        std::string name; // Name of the item
        // Item ID
        int ID;

        // Constructor that accepts a name
        ItemDetails(const std::string& itemName, int ID)
            : name(itemName),
            ID(0) {}
    };

    ItemDetails details; // Instance of ItemDetails
};

} // namespace game
