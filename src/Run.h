//
// Created by Kye Nelson on 6/22/25.
//
#pragma once

#include <BaseGame.h>

namespace Zuno
{
    void Run(BaseGame& game)
    {
        game.OnLoad();

        while (true)
        {
            // event

            game.OnUpdate();
            game.OnDraw();
        }

        game.OnQuit();
    }
}
