//
// Created by Kye Nelson on 6/22/25.
//
#pragma once

#include <SDL3/SDL.h>

namespace Zuno
{
    class Window
    {
    public:
        Window();
        ~Window();

    private:
        SDL_Window* m_SDLWindow = nullptr;

    public:
        friend class Graphics;
    };
}
