#pragma once
#include "inventory.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace game {
/**
 * @brief The InventoryManager class
 * This class is for managing all of the game inventories.
 * This is where inventories will be created and destroyed and managed.
 */
class InventoryManager
{
public:
    InventoryManager();
    /**
     * @brief createNewInventory
     * @param name
     * @param ID
     * @param rows
     * @param colums
     * @return
     */
    game::Inventory* createNewInventory(std::string name, int ID, int rows, int colums);
    /**
     * @brief getInventoryByID
     * @param ID
     */
    void getInventoryByID(int ID);
    /**
     * @brief getInventoryByName
     * @param name
     */
    void getInventoryByName(std::string name);
    /**
     * @brief clearInventory
     * @param ID
     */
    void clearInventory(int ID);

    /**
     * @brief getInventories
     * @return
     */
    std::vector<game::Inventory> getInventories() const;
    /**
     * @brief setInventories
     * @param newInventories
     */
    void setInventories(const std::vector<game::Inventory> &newInventories);

private:
    /**
     * @brief inventories
     */
    std::vector<game::Inventory> inventories;
};

}
