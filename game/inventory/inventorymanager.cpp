#include "inventorymanager.hpp"

namespace game {
game::Inventory* InventoryManager::createNewInventory(std::string name, int ID, int rows, int columns)
{
    game::Inventory* newInv = new game::Inventory(ID, name, rows, columns);
    return newInv;
}

void InventoryManager::getInventoryByID(int ID)
{

}

void InventoryManager::getInventoryByName(std::string name)
{

}

void InventoryManager::clearInventory(int ID)
{

}

std::vector<game::Inventory> InventoryManager::getInventories() const
{
    return inventories;
}

void InventoryManager::setInventories(const std::vector<game::Inventory> &newInventories)
{
    inventories = newInventories;
}

}

