// --- Engine ---
// Created by Kye Nelson on 6/21/25.
// Main application class for Zuno
#pragma once

#include "Window.h"
#include "Graphics.h"
#include <memory>

namespace Zuno
{
    class BaseGame;

    class Engine
    {
    public:
        Engine();
        ~Engine() {};

        void Run(BaseGame& game);

        const Window& GetWindow() const { return *m_Window; }
        const Graphics& GetGraphics() const { return *m_Graphics; }

    private:
        std::unique_ptr<Window> m_Window = nullptr;
        std::unique_ptr<Graphics> m_Graphics = nullptr;
        bool IsRunning = true;
    };
}
