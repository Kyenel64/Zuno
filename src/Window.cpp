//
// Created by Kye Nelson on 6/22/25.
//

#include "Window.h"

namespace Zuno
{
    Window::Window()
    {
        SDLWindow = SDL_CreateWindow("Test", 1920, 1080, 0);
        if (SDLWindow == nullptr)
            std::cerr << "Window could not be created! SDL_Error: %s\n" << SDL_GetError() << std::endl;
    }
}
