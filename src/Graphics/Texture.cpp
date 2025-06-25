//
// Created by Kye Nelson on 6/23/25.
//
#include "Texture.h"

namespace Zuno
{
    Texture::Texture(SDL_Renderer* renderer, std::string path) : m_Path(std::move(path))
    {
        m_SDLTexture = IMG_LoadTexture(renderer, m_Path.c_str());
        SDL_assert(m_SDLTexture != nullptr);
    }
}
