//
// Created by Kye Nelson on 6/23/25.
//
#include "Graphics.h"

#include "Window.h"
#include "Texture.h"
#include "Surface.h"

#include <SDL3/SDL.h>

namespace Zuno
{
    Graphics::Graphics(const Window& window)
        : m_Window(window)
    {
        m_SDLRenderer = SDL_CreateRenderer(m_Window.m_SDLWindow, nullptr);
        SDL_assert(m_SDLRenderer != nullptr);
    }

    Graphics::~Graphics()
    {
        SDL_DestroyRenderer(m_SDLRenderer);
        m_SDLRenderer = nullptr;
    }

    Texture* Graphics::CreateTexture(const std::string& path)
    {
        return new Texture(m_SDLRenderer, path);
    }

    Surface* Graphics::CreateSurface(const std::string& path)
    {
        return new Surface(m_SDLRenderer, path);
    }



    void Graphics::Clear() const
    {
        SDL_SetRenderDrawColor(m_SDLRenderer, 0, 255, 0, 255); // temp
        SDL_RenderClear(m_SDLRenderer);
    }

    void Graphics::Present() const
    {
        SDL_RenderPresent(m_SDLRenderer);
    }

    void Graphics::DrawPoint(const float x, const float y) const
    {
        SDL_SetRenderDrawColor(m_SDLRenderer, 255, 0, 0, 255); // temp
        SDL_RenderPoint(m_SDLRenderer, x, y);
    }

    void Graphics::DrawLine(const float x1, const float y1, const float x2, const float y2) const
    {
        SDL_SetRenderDrawColor(m_SDLRenderer, 255, 0, 0, 255); // temp
        SDL_RenderLine(m_SDLRenderer, x1, y1, x2, y2);
    }

    void Graphics::DrawTexture(const Texture* texture)
    {
        SDL_RenderTexture(m_SDLRenderer, texture->m_SDLTexture, nullptr, nullptr);
    }
}
