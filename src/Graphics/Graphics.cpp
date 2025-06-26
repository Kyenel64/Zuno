//
// Created by Kye Nelson on 6/23/25.
//
#include "Graphics.h"

#include "Window.h"
#include "Texture.h"
#include "Graphics/ImageData.h"
#include "Graphics/Rect.h"

#include <SDL3/SDL.h>
#include <glm/glm.hpp>

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

    Texture* Graphics::CreateTexture(const ImageData* imageData)
    {
        return new Texture(m_SDLRenderer, imageData->m_SDLSurface);
    }

    ImageData* Graphics::CreateImageData(const std::string& path)
    {
        return new ImageData(m_SDLRenderer, path);
    }

    Rect* Graphics::CreateRect(float x1, float y1, float x2, float y2)
    {
        return new Rect(m_SDLRenderer, x1, y1, x2, y2);
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

    void Graphics::DrawQuad(const Rect& rect)
    {
        SDL_RenderRect(m_SDLRenderer, &rect.m_SDLFRect);
    }

    void Graphics::Draw(const Texture& texture, const glm::vec2& position, float rotation,
                        const glm::vec2& scale, const glm::vec2& originOffset)
    {
        SDL_FPoint offsetPoint = { originOffset.x, originOffset.y };
        SDL_FRect rect(position.x - originOffset.x, position.y - originOffset.y, scale.x, scale.y);
        SDL_RenderTextureRotated(m_SDLRenderer, texture.m_SDLTexture, nullptr, &rect, rotation, &offsetPoint, SDL_FlipMode::SDL_FLIP_NONE);
    }

    void Graphics::Draw(const Texture& texture, const Rect& rect, const glm::vec2& position, float rotation,
        const glm::vec2& scale, const glm::vec2& originOffset)
    {
        SDL_FPoint offsetPoint = { originOffset.x, originOffset.y };
        SDL_FRect dstRect(position.x - originOffset.x, position.y - originOffset.y, scale.x, scale.y);
        SDL_RenderTextureRotated(m_SDLRenderer, texture.m_SDLTexture, &rect.m_SDLFRect, &dstRect, rotation, &offsetPoint, SDL_FlipMode::SDL_FLIP_NONE);
    }
}
