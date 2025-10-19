//
// Created by Kye Nelson on 10/17/25.
//

#pragma once

#include <string>
#include <functional>

class GLFWwindow;

namespace Zuno
{
    class Event;

    class Window
    {
    public:
        Window(const std::string& title, uint32_t width, uint32_t height, bool maximize = false);
        ~Window();

        [[nodiscard]] bool ShouldClose() const;

        void SetShouldClose(bool value) const;

        void PollEvents();
        void DispatchEvent(Event& event) const { if (m_EventCallback) m_EventCallback(event); }

        template<typename Fn>
        void SetEventCallback(Fn&& eventFn) { m_EventCallback = std::forward<Fn>(eventFn); }

    private:
        void RegisterCallbacks() const;

    private:
        GLFWwindow* m_GLFWwindow = nullptr;

        uint32_t m_Width, m_Height;
        std::function<void(Event&)> m_EventCallback = nullptr;
    };
}
