//
// Created by Kye Nelson on 6/22/25.
//

#include "Window.h"

namespace Zuno
{
    Window::Window()
    {
        m_SDLWindow = SDL_CreateWindow("Zuno", 1280, 720, 0);
        SDL_assert(m_SDLWindow != nullptr);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_SDLWindow);
        m_SDLWindow = nullptr;
    }

    void Window::SetTitle(const std::string& title)
    {
        SDL_SetWindowTitle(m_SDLWindow, title.c_str());
    }

    const char* Window::GetTitle() const
    {
        return SDL_GetWindowTitle(m_SDLWindow);
    }

    void Window::SetPosition(int x, int y)
    {
        SDL_SetWindowPosition(m_SDLWindow, x, y);
    }

    glm::vec2 Window::GetPosition() const
    {
        int x, y;
        SDL_GetWindowPosition(m_SDLWindow, &x, &y);
        return glm::vec2(x,  y);
    }
}
