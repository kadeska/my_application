#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "item.hpp"

namespace game {
class Inventory
{
public:
    Inventory();
    Inventory(int inv_ID, std::string inv_name, int inv_rows, int inv_columns);

    void displayInventory();
    void hideInventory();
    void printInventory();
    bool addItem(Item item);
    bool removeItem(Item item);
    std::vector<game::Item> getInventory();

    void setInventory(const std::vector<game::Item> &newInventory);

private:
    std::vector<game::Item> inventory;
    int ID, rows, columns;

};

}
