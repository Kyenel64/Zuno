// --- Engine ---
// Created by Kye Nelson on 6/21/25.
// Main application class for Zuno
#pragma once

#include "Window.h"
#include "Graphics.h"

namespace Zuno
{
    class BaseGame;

    class Engine
    {
    public:
        Engine();
        ~Engine() {};

        void Run(BaseGame& game);

    private:
        std::unique_ptr<Window> Window = nullptr;
        std::unique_ptr<Graphics> Graphics = nullptr;
        bool IsRunning = true;
    };
}
