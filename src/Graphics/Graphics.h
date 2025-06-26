// --- Graphics.h ---
// Created by Kye Nelson on 6/23/25.
// Graphics subsystem. Manages all rendering.
#pragma once

#include <string>
#include <glm/glm.hpp>

class SDL_Renderer;

namespace Zuno
{
    class Window;
    class Texture;
    class ImageData;
    class Rect;

    class Graphics
    {
    public:
        explicit Graphics(const Window& window);
        ~Graphics();

        void Clear() const;
        void Present() const;

        void DrawPoint(float x, float y) const;
        void DrawLine(float x1, float y1, float x2, float y2) const;
        void DrawQuad(const Rect& rect);
        void Draw(const Texture& texture, const glm::vec2& position, float rotation = 0,
            const glm::vec2& scale = glm::vec2(1.0f), const glm::vec2& originOffset = glm::vec2(0.0f));
        void Draw(const Texture& texture, const Rect& rect, const glm::vec2& position, float rotation = 0,
            const glm::vec2& scale = glm::vec2(1.0f), const glm::vec2& originOffset = glm::vec2(0.0f));

        Texture* CreateTexture(const std::string& path);
        Texture* CreateTexture(const ImageData* imageData);
        ImageData* CreateImageData(const std::string& path);
        Rect* CreateRect(float x1, float y1, float x2, float y2);


    private:
        SDL_Renderer* m_SDLRenderer = nullptr;
        const Window& m_Window;
    };
}
