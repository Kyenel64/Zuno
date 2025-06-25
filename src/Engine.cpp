//
// Created by Kye Nelson on 6/21/25.
//

#include "Engine.h"
#include "BaseGame.h"

#include <SDL3/SDL.h>

namespace Zuno
{
    Engine::Engine()
    {
        bool success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        SDL_assert(success);

        m_Window = std::make_unique<Zuno::Window>();
        m_Graphics = std::make_unique<Zuno::Graphics>(*m_Window);

        SDL_Log("Initialized Engine");
    }

    Engine::~Engine()
    {
        m_Graphics.reset();
        m_Window.reset();
        SDL_Quit();

        SDL_Log("Shutdown Engine");
    }

    void Engine::Run(BaseGame& game)
    {
        game.OnLoad();

        while (IsRunning)
        {
            SDL_Event event;
            SDL_PollEvent(&event);
            switch (event.type)
            {
                case SDL_EVENT_QUIT: IsRunning = false; break;
                case SDL_EVENT_KEY_DOWN: game.OnKeyPressed(static_cast<KeyCode>(event.key.scancode)); break;
                case SDL_EVENT_WINDOW_RESIZED: game.OnWindowResized(event.display.data1, event.display.data2); break;
                default: break;
            }

            game.OnUpdate();

            m_Graphics->Clear();
            game.OnDraw();
            m_Graphics->Present();
        }

        game.OnQuit();
    }

}
