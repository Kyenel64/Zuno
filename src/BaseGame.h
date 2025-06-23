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

        void Run() { Engine.Run(*this); }

    protected:
        explicit BaseGame(Engine& engine) : Engine(engine) {}

        Engine& Engine;
    };
}
