// --- Surface.h ---
// Created by Kye Nelson on 6/25/25.
// Surface object. CPU side image data.
#pragma once

#include <string>

class SDL_Renderer;
class SDL_Surface;

namespace Zuno
{
    class Surface
    {
    private:
        Surface(SDL_Renderer* renderer, std::string path);
        Surface(SDL_Surface* surface);

    private:
        SDL_Surface* m_SDLSurface = nullptr;
        std::string m_Path;

    public:
        friend class Graphics;
        friend class Window;
    };
}
