// --- Graphics.h ---
// Created by Kye Nelson on 6/23/25.
// Graphics subsystem. Manages all rendering.
#pragma once

#include <string>

class SDL_Renderer;

namespace Zuno
{
    class Window;
    class Texture;
    class ImageData;

    class Graphics
    {
    public:
        explicit Graphics(const Window& window);
        ~Graphics();

        void Clear() const;
        void Present() const;

        void DrawPoint(float x, float y) const;
        void DrawLine(float x1, float y1, float x2, float y2) const;
        void DrawTexture(const Texture* texture);

        Texture* CreateTexture(const std::string& path);
        Texture* CreateTexture(const ImageData* imageData);
        ImageData* CreateImageData(const std::string& path);

    private:
        SDL_Renderer* m_SDLRenderer = nullptr;
        const Window& m_Window;
    };
}
