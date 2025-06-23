//
// Created by Kye Nelson on 6/23/25.
//
#pragma once

#include "Utils/Log.h"
#include <SDL3_image/SDL_image.h>
#include <string>

namespace Zuno
{
    class Texture
    {
    private:
        Texture(SDL_Renderer* renderer, std::string path) : m_Path(std::move(path))
        {
            m_SDLTexture = IMG_LoadTexture(renderer, m_Path.c_str());
            ZUNO_ASSERT(m_SDLTexture != nullptr, "Could not load texture! SDL_Error: %s", SDL_GetError());
        }

    private:
        SDL_Texture* m_SDLTexture = nullptr;
        std::string m_Path;

    public:
        friend class Graphics;
    };
}
