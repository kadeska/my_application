#pragma once
#include "../../game/core/gamecore.hpp"

class OpenglWindow
{
public:
    OpenglWindow(GameCore* gameCore);
    void startRenderLoop();

private:
    GameCore* gameCore;
};
