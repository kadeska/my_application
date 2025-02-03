#pragma once
#include "inventory.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace game {
class InventoryManager
{
public:
    InventoryManager();
    game::Inventory* createNewInventory(std::string name, int ID, int rows, int colums);
    void getInventoryByID(int ID);
    void getInventoryByName(std::string name);
    void clearInventory(int ID);

    std::vector<game::Inventory> getInventories() const;
    void setInventories(const std::vector<game::Inventory> &newInventories);

private:
    std::vector<game::Inventory> inventories;
};

}
