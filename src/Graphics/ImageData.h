// --- Surface.h ---
// Created by Kye Nelson on 6/25/25.
// Raw image data object. Stores image in raw bytes. Cannot be used for render. Must create a texture first.
#pragma once

#include <string>

class SDL_Renderer;
class SDL_Surface;

namespace Zuno
{
    class ImageData
    {
    public:
        ~ImageData();
    private:
        ImageData(SDL_Renderer* renderer, std::string path);

    private:
        SDL_Surface* m_SDLSurface = nullptr;
        std::string m_Path;

    public:
        friend class Graphics;
        friend class Window;
    };
}
