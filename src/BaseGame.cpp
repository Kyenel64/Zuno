// --- BaseGame.cpp ---
// Created by Kye Nelson on 6/22/25.
//
#include "BaseGame.h"

#include "Engine.h"

namespace Zuno
{
    void BaseGame::Run()
    {
        Engine.Run(*this);
    }
}
