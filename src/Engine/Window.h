//
// Created by Kye Nelson on 10/17/25.
//

#pragma once

#include <string>
#include <functional>

class Event;
class GLFWwindow;

class Window
{
public:
    Window(const std::string& title, uint32_t width, uint32_t height, bool maximize = false);
    ~Window();

    [[nodiscard]] bool ShouldClose() const;

    void PollEvents();

    template<typename Fn>
    void SetEventCallback(Fn&& eventFn) { m_EventCallback = std::forward<Fn>(eventFn); }

private:
    void RegisterCallbacks() const;

private:
    GLFWwindow* m_GLFWwindow = nullptr;

    uint32_t m_Width, m_Height;
    std::function<void(Event&)> m_EventCallback;
};
