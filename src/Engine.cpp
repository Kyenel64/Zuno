//
// Created by Kye Nelson on 6/21/25.
//

#include "Engine.h"
#include "BaseGame.h"
#include "Utils/Log.h"

#include <SDL3/SDL.h>

namespace Zuno
{
    Engine::Engine()
    {
        bool success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        ZUNO_ASSERT(success, "Failed to initialize SDL: %s", SDL_GetError());

        m_Window = std::make_unique<Zuno::Window>();
        m_Graphics = std::make_unique<Zuno::Graphics>(*m_Window);
    }

    Engine::~Engine()
    {
        SDL_Quit();
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
                case SDL_EVENT_KEY_DOWN: game.OnKeyPressed(static_cast<KeyCode>(event.key.scancode));
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
