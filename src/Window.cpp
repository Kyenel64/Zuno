// --- Window.cpp ---
// Created by Kye Nelson on 6/22/25.
//
#include "Window.h"

#include "Graphics/ImageData.h"

#include <SDL3/SDL.h>

namespace Zuno
{
    Window::Window()
    {
        SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE;
        m_SDLWindow = SDL_CreateWindow("Zuno", 1280, 720, flags);
        SDL_assert(m_SDLWindow != nullptr);

        SDL_Log("Initialized Window");
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_SDLWindow);
        m_SDLWindow = nullptr;

        SDL_Log("Shutdown Window");
    }


    void Window::SetTitle(const std::string& title)
    {
        SDL_SetWindowTitle(m_SDLWindow, title.c_str());
    }

    void Window::SetPosition(int x, int y)
    {
        SDL_SetWindowPosition(m_SDLWindow, x, y);
    }

    void Window::SetVSync(bool value)
    {
        SDL_SetWindowSurfaceVSync(m_SDLWindow, value);
    }

    void Window::SetFullscreen(bool value)
    {
        SDL_SetWindowFullscreen(m_SDLWindow, value);
    }

    void Window::Minimize()
    {
        SDL_MinimizeWindow(m_SDLWindow);
    }

    void Window::Maximize()
    {
        SDL_MaximizeWindow(m_SDLWindow);
    }

    void Window::SetIcon(const ImageData* imageData)
    {
        if (!SDL_SetWindowIcon(m_SDLWindow, imageData->m_SDLSurface))
            SDL_LogError(SDL_LOG_CATEGORY_GPU, "Failed to set icon. %s", SDL_GetError());
    }


    const char* Window::GetTitle() const
    {
        return SDL_GetWindowTitle(m_SDLWindow);
    }

    glm::vec2 Window::GetPosition() const
    {
        int x, y;
        SDL_GetWindowPosition(m_SDLWindow, &x, &y);
        return {x,  y};
    }

    glm::vec2 Window::GetSize() const
    {
        int x, y;
        SDL_GetWindowSize(m_SDLWindow, &x, &y);
        return {x,  y};
    }

    glm::vec2 Window::GetDesktopSize() const
    {
        const SDL_DisplayMode* mode = SDL_GetDesktopDisplayMode(SDL_GetDisplayForWindow(m_SDLWindow));
        return { mode->w, mode->h };
    }

    bool Window::GetVSync() const
    {
        int isOn;
        SDL_GetWindowSurfaceVSync(m_SDLWindow, &isOn);
        return isOn;
    }

    bool Window::IsFullscreen() const
    {
        SDL_WindowFlags flags = SDL_GetWindowFlags(m_SDLWindow); // TODO: optimize?
        return flags & SDL_WINDOW_FULLSCREEN;
    }

    bool Window::IsMinimized() const
    {
        SDL_WindowFlags flags = SDL_GetWindowFlags(m_SDLWindow); // TODO: optimize?
        return flags & SDL_WINDOW_MINIMIZED;
    }

    bool Window::IsMaximized() const
    {
        SDL_WindowFlags flags = SDL_GetWindowFlags(m_SDLWindow); // TODO: optimize?
        return flags & SDL_WINDOW_MAXIMIZED;
    }

    const char* Window::GetDisplayName(int displayIndex) const
    {
        const char* displayName = SDL_GetDisplayName(displayIndex);
        if (!displayName)
            SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "Could not detect display at index: %i. %s", displayIndex, SDL_GetError());
        return displayName;
    }

    uint32_t Window::GetDisplayCount() const
    {
        int count;
        SDL_GetDisplays(&count);
        if (count == 0)
            SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "Could not detect any displays. %s", SDL_GetError());
        return count;
    }

    DisplayOrientation Window::GetDisplayOrientation() const
    {
        SDL_DisplayOrientation orientation = SDL_GetCurrentDisplayOrientation(SDL_GetDisplayForWindow(m_SDLWindow));
        return static_cast<DisplayOrientation>(orientation);
    }

    float Window::GetDPIScale() const
    {
        return SDL_GetWindowDisplayScale(m_SDLWindow);
    }

    bool Window::IsVisible() const
    {
        SDL_WindowFlags flags = SDL_GetWindowFlags(m_SDLWindow); // TODO: optimize?
        return flags & SDL_WINDOW_HIDDEN;
    }

    bool Window::IsCreated() const
    {
        return m_SDLWindow != nullptr;
    }

    bool Window::HasMouseFocus() const
    {
        return SDL_GetMouseFocus() == m_SDLWindow;
    }

    bool Window::HasKeyboardFocus() const
    {
        return SDL_GetKeyboardFocus() == m_SDLWindow;
    }
}
