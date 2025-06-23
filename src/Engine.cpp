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
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == false)
            std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;

        Window = std::make_unique<Zuno::Window>();
        Graphics = std::make_unique<Zuno::Graphics>(*Window);
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
                default: break;
            }

            game.OnUpdate();

            Graphics->Clear();
            game.OnDraw();
            Graphics->Present();
        }

        game.OnQuit();
    }

}
