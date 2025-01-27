#pragma once

#include <../../game/entity/myentity.hpp>
#include <string>
#include <iostream>

/**
 * @brief The EntityBase class. This class
 * is the base entity class for an object
 * in the world. This will inherate the
 * 3d/2d object class to store model data
 * and other data needed for model needs.
 * This wont contain any game related things
 * as this is just to represent the 3d/2d model.
 *
 */
class EntityBase //** : public BaseModel */
{
public:
    EntityBase();
    void init(//** Model model, Texture texture, Position pos  */
        std::string name
        );
};
