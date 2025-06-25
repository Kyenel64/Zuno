// --- BaseGame.h ---
// Created by Kye Nelson on 6/22/25.
// Superclass for all games using Zuno.
#pragma once

#include "Key.h"

namespace Zuno
{
    class Engine;

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

        void Run();

    protected:
        explicit BaseGame(Engine& engine) : Engine(engine) {}

        Engine& Engine;
    };
}
