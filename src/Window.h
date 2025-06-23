//
// Created by Kye Nelson on 6/22/25.
//
#pragma once

#include <iostream>
#include <SDL3/SDL.h>

namespace Zuno
{
    class Window
    {
    public:
        Window();

        SDL_Window* GetSDLWindow() const { return SDLWindow;}

    private:
        SDL_Window* SDLWindow = nullptr;
    };
}
