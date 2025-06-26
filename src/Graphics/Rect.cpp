//
// Created by Kye Nelson on 6/26/25.
//
#include "Rect.h"

namespace Zuno
{
    Rect::Rect(SDL_Renderer* renderer, float x1, float y1, float x2, float y2)
        : m_SDLFRect(x1, y1, x2, y2)
    {
    }
}
