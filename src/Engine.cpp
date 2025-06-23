//
// Created by Kye Nelson on 6/21/25.
//

#include "Engine.h"
#include "BaseGame.h"

#include <SDL3/SDL.h>
#include <iostream>

namespace Zuno
{
    Engine::Engine()
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == false)
            std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;

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
