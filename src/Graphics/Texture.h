//
// Created by Kye Nelson on 6/23/25.
//
#pragma once

#include <SDL3_image/SDL_image.h>
#include <string>

namespace Zuno
{
    class Texture
    {
    private:
        Texture(SDL_Renderer* renderer, std::string path);

    private:
        SDL_Texture* m_SDLTexture = nullptr;
        std::string m_Path;

    public:
        friend class Graphics;
    };
}
