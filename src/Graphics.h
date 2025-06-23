//
// Created by Kye Nelson on 6/23/25.
//
#pragma once

#include <SDL3/SDL.h>

#include "Window.h"
#include <memory>

namespace Zuno
{
    class Graphics
    {
    public:
        explicit Graphics(const Window& window);
        ~Graphics();

        void Clear() const;
        void Present() const;

        void DrawPoint(float x, float y) const;
        void DrawLine(float x1, float y1, float x2, float y2) const;

    private:
        SDL_Renderer* SDLRenderer = nullptr;
        const Window& m_Window;
    };
}
