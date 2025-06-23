//
// Created by Kye Nelson on 6/23/25.
//
#pragma once

#include <SDL3_image/SDL_image.h>
#include <iostream>

namespace Zuno
{
    class Texture
    {
    private:
        Texture(SDL_Renderer* renderer, std::string path) : m_Path(std::move(path))
        {
            m_SDLTexture = IMG_LoadTexture(renderer, m_Path.c_str());
            if (m_SDLTexture == nullptr)
                std::cerr << "Could not load texture! SDL_Error: %s\n" << SDL_GetError() << std::endl;
        }

    private:
        SDL_Texture* m_SDLTexture = nullptr;
        std::string m_Path;

    public:
        friend class Graphics;
    };
}
