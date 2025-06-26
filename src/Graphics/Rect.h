//
// Created by Kye Nelson on 6/26/25.
//
#pragma once

#include <SDL3/SDL.h>

class SDL_Renderer;

namespace Zuno
{
    class Rect
    {
    public:
        Rect(SDL_Renderer* renderer, float x1, float y1, float x2, float y2);
        ~Rect() = default;

    private:
        SDL_FRect m_SDLFRect;

    public:
        friend class Graphics;
    };
}
