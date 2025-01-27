#pragma once

#include "../../glWindow/gl/entity/entitybase.hpp"
#include <iostream>
#include <string>

/**
 * BaseEntity is the namespace for MyEntity
 * as it represents the base entity class.
 * This class will be for the in-game
 * representation of the base entity. In
 * this case it's just a base entity so
 * there is not much here.
 *
 */
namespace BaseEntity {

class MyEntity {
public:
    MyEntity() : name("Unnamed") {}
    MyEntity(const std::string& baseEntityName);
    std::string name;
};

}

