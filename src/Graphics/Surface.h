//
// Created by Kye Nelson on 6/25/25.
//
#pragma once

#include <../../thirdparty/SDL_image/include/SDL3_image/SDL_image.h>
#include <string>

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
