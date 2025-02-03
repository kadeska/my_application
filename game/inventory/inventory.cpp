#include "inventory.hpp"
#include "../../helper.hpp"

namespace game {
Inventory::Inventory() {
    helper.log(3, "Inventory() ");
}

Inventory::Inventory(int inv_ID, std::string inv_name, int inv_rows, int inv_columns)
{

}

void Inventory::displayInventory()
{

}

void Inventory::hideInventory()
{

}

void Inventory::printInventory()
{
    try {
        for (const Item& item : inventory) {
            item.printDetails();
        }
    } catch (...) {
    }

}

bool Inventory::addItem(Item item)
{
    return false;
}

bool Inventory::removeItem(Item item)
{
    return false;
}

void Inventory::setInventory(const std::vector<game::Item> &newInventory)
{
    inventory = newInventory;
}

std::vector<Item> Inventory::getInventory()
{
    return inventory;
}
}
