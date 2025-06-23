//
// Created by Kye Nelson on 6/23/25.
//
#include "Graphics.h"

namespace Zuno
{
    Graphics::Graphics(const Window& window)
    {
        SDLRenderer = SDL_CreateRenderer(window.GetSDLWindow(), nullptr);
        if (SDLRenderer == nullptr)
            std::cerr << "Renderer could not be created! SDL_Error: %s\n" << SDL_GetError() << std::endl;
    }
}
