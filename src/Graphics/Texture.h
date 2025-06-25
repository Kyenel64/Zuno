// --- Texture.h ---
// Created by Kye Nelson on 6/23/25.
// Texture object. GPU side image data for rendering.
#pragma once

#include <string>

class SDL_Renderer;
class SDL_Texture;

namespace Zuno
{
    class Texture
    {
    private:
        Texture(SDL_Renderer* renderer, std::string path);

    private:
        SDL_Texture* m_SDLTexture = nullptr;
        std::string m_Path;

    public:
        friend class Graphics;
    };
}
