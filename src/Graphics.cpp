//
// Created by Kye Nelson on 6/23/25.
//
#include "Graphics.h"
#include <iostream>

namespace Zuno
{
    Graphics::Graphics(const Window& window)
        : m_Window(window)
    {
        SDLRenderer = SDL_CreateRenderer(m_Window.m_SDLWindow, nullptr);
        if (SDLRenderer == nullptr)
            std::cerr << "Renderer could not be created! SDL_Error: %s\n" << SDL_GetError() << std::endl;
    }

    Graphics::~Graphics()
    {
        SDL_DestroyRenderer(SDLRenderer);
        SDLRenderer = nullptr;
    }


    void Graphics::Clear() const
    {
        SDL_SetRenderDrawColor(SDLRenderer, 0, 255, 0, 255); // temp
        SDL_RenderClear(SDLRenderer);
    }

    void Graphics::Present() const
    {
        SDL_RenderPresent(SDLRenderer);
    }

    void Graphics::DrawPoint(const float x, const float y) const
    {
        SDL_SetRenderDrawColor(SDLRenderer, 255, 0, 0, 255); // temp
        SDL_RenderPoint(SDLRenderer, x, y);
    }

    void Graphics::DrawLine(const float x1, const float y1, const float x2, const float y2) const
    {
        SDL_SetRenderDrawColor(SDLRenderer, 255, 0, 0, 255); // temp
        SDL_RenderLine(SDLRenderer, x1, y1, x2, y2);
    }
}
