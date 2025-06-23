//
// Created by Kye Nelson on 6/22/25.
//

#include "Window.h"
#include <iostream>

namespace Zuno
{
    Window::Window()
    {
        m_SDLWindow = SDL_CreateWindow("Test", 1920, 1080, 0);
        if (m_SDLWindow == nullptr)
            std::cerr << "Window could not be created! SDL_Error: %s\n" << SDL_GetError() << std::endl;
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_SDLWindow);
        m_SDLWindow = nullptr;
    }
}
