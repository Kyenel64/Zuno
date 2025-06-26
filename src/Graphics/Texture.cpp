// --- Texture.cpp ---
// Created by Kye Nelson on 6/23/25.
//
#include "Texture.h"

#include <SDL3_image/SDL_image.h>

namespace Zuno
{
    Texture::Texture(SDL_Renderer* renderer, std::string path) : m_Path(std::move(path))
    {
        m_SDLTexture = IMG_LoadTexture(renderer, m_Path.c_str());
        SDL_assert(m_SDLTexture != nullptr);
    }

    Texture::Texture(SDL_Renderer* renderer, SDL_Surface* surface)
    {
        m_SDLTexture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_assert(m_SDLTexture != nullptr);
    }

    Texture::~Texture()
    {
        SDL_DestroyTexture(m_SDLTexture);
        m_SDLTexture = nullptr;
    }

}
