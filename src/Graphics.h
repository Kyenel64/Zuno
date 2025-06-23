//
// Created by Kye Nelson on 6/23/25.
//
#pragma once

#include <SDL3/SDL.h>

#include "Window.h"

namespace Zuno
{
    class Graphics
    {
    public:
        explicit Graphics(const Window& window);

        void Clear() const
        {
            SDL_SetRenderDrawColor(SDLRenderer, 0, 255, 0, 255);
            SDL_RenderClear(SDLRenderer);
        }
        void Present() const { SDL_RenderPresent(SDLRenderer); }

    private:
        SDL_Renderer* SDLRenderer = nullptr;

    };
}
