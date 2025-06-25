// --- Window.h ---
// Created by Kye Nelson on 6/22/25.
// Window subsystem. Manages all window related functions.
#pragma once

#include <glm/glm.hpp>

class SDL_Window;

namespace Zuno
{
    class Surface;

    typedef enum DisplayOrientation
    {
        DISPLAY_ORIENTATION_UNKNOWN,
        DISPLAY_ORIENTATION_LANDSCAPE,
        DISPLAY_ORIENTATION_LANDSCAPE_FLIPPED,
        DISPLAY_ORIENTATION_PORTRAIT,
        DISPLAY_ORIENTATION_PORTRAIT_FLIPPED
    } DisplayOrientation;

    class Window
    {
    public:
        Window();
        ~Window();

        void SetTitle(const std::string& title);
        void SetPosition(int x, int y);
        void SetVSync(bool value);
        void SetFullscreen(bool value);
        void Minimize();
        void Maximize();
        void SetIcon(const Surface* surface);

        const char* GetTitle() const;
        glm::vec2 GetPosition() const;
        glm::vec2 GetSize() const;
        glm::vec2 GetDesktopSize() const;
        bool GetVSync() const;
        bool IsFullscreen() const;
        bool IsMinimized() const;
        bool IsMaximized() const;
        const char* GetDisplayName(int displayIndex) const;
        uint32_t GetDisplayCount() const;
        DisplayOrientation GetDisplayOrientation() const;
        float GetDPIScale() const;
        bool IsVisible() const;
        bool IsCreated() const;
        bool HasMouseFocus() const;
        bool HasKeyboardFocus() const;

    private:
        SDL_Window* m_SDLWindow = nullptr;

    public:
        friend class Graphics;
    };
}
