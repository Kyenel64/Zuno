// --- Game ---
// Created by Kye Nelson on 6/22/25.
//
#pragma once

#include "Engine.h"

namespace Zuno
{
    class BaseGame
    {
    public:
        virtual ~BaseGame() = default;

        virtual void OnLoad() {}
        virtual void OnUpdate() {}
        virtual void OnDraw() {}
        virtual void OnQuit() {}

        virtual void OnKeyPressed(int key) {}

    protected:
        explicit BaseGame(const Engine& engine) : Engine(engine) {}

        const Engine& Engine;
    };
}
