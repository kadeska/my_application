#pragma once
#include "../../game/core/gamecore.hpp"

class OpenglWindow
{
public:
    OpenglWindow(GameCore* gameCore);

private:
    GameCore* gameCore;
};
