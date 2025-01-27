#include "myentity.hpp"

namespace BaseEntity {

std::string name;

MyEntity::MyEntity(const std::string& baseEntityName)
    : name(baseEntityName) // Initialize the `name` member
{
    // Optional logic if needed
}

}
