// --- Texture.h ---
// Created by Kye Nelson on 6/23/25.
// Texture object. GPU side image data for rendering.
#pragma once

#include <string>

class SDL_Renderer;
class SDL_Texture;
class SDL_Surface;

namespace Zuno
{
    class Texture
    {
    public:
        ~Texture();
    private:
        Texture(SDL_Renderer* renderer, std::string path);
        Texture(SDL_Renderer* renderer, SDL_Surface* surface);

    private:
        SDL_Texture* m_SDLTexture = nullptr;
        std::string m_Path;

    public:
        friend class Graphics;
    };
}
