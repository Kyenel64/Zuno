//
// Created by Kye Nelson on 6/22/25.
//

#include "Window.h"

namespace Zuno
{
    Window::Window()
    {
        m_SDLWindow = SDL_CreateWindow("Test", 1920, 1080, 0);
        SDL_assert(m_SDLWindow != nullptr);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_SDLWindow);
        m_SDLWindow = nullptr;
    }
}
