// --- Engine.h ---
// Created by Kye Nelson on 6/21/25.
// Main engine class for Zuno. Only contains the main run loop and all the subsystems for Zuno.
#pragma once

#include <memory>

namespace Zuno
{
    class BaseGame;
    class Window;
    class Graphics;

    class Engine
    {
    public:
        Engine();
        ~Engine();

        Window& GetWindow() const { return *m_Window; }
        Graphics& GetGraphics() const { return *m_Graphics; }

    private:
        void Run(BaseGame& game);

    private:
        std::unique_ptr<Window> m_Window = nullptr;
        std::unique_ptr<Graphics> m_Graphics = nullptr;
        bool IsRunning = true;

    public:
        friend class BaseGame;
    };
}
