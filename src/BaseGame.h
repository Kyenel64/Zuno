// --- Game ---
// Created by Kye Nelson on 6/22/25.
//
#pragma once

#include "Engine.h"
#include "Key.h"

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

        virtual void OnKeyPressed(KeyCode key) {}
        virtual void OnWindowResized(int w, int h) {}

        void Run() { Engine.Run(*this); }

    protected:
        explicit BaseGame(Engine& engine) : Engine(engine) {}

        Engine& Engine;
    };
}
