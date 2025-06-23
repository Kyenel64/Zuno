//
// Created by Kye Nelson on 6/22/25.
//

#include "Window.h"
#include "Utils/Log.h"

namespace Zuno
{
    Window::Window()
    {
        m_SDLWindow = SDL_CreateWindow("Test", 1920, 1080, 0);
        ZUNO_ASSERT(m_SDLWindow != nullptr, "Window could not be created! SDL_Error: %s", SDL_GetError());
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_SDLWindow);
        m_SDLWindow = nullptr;
    }
}
