// --- Surface.cpp ---
// Created by Kye Nelson on 6/25/25.
//
#include "Surface.h"

#include <SDL3_image/SDL_image.h>

namespace Zuno
{
    Surface::Surface(SDL_Renderer* renderer, std::string path) : m_Path(std::move(path))
    {
        m_SDLSurface = IMG_Load(m_Path.c_str());
        SDL_assert(m_SDLSurface != nullptr);
    }
}
