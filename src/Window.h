//
// Created by Kye Nelson on 6/22/25.
//
#pragma once

#include <SDL3/SDL.h>
#include <string>
#include <glm/glm.hpp>

namespace Zuno
{
    class Window
    {
    public:
        Window();
        ~Window();

        void SetTitle(const std::string& title);
        void SetPosition(int x, int y);

        const char* GetTitle() const;
        glm::vec2 GetPosition() const;

    private:
        SDL_Window* m_SDLWindow = nullptr;

    public:
        friend class Graphics;
    };
}
