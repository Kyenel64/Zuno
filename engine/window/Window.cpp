//
// Created by Kye Nelson on 10/17/25.
//

#include "core/ZunoPCH.h"
#include "Window.h"

#include <cassert>
#include <iostream>
#include <GLFW/glfw3.h>

#include "event/Event.h"

namespace Zuno
{
    static void GLFWErrorCallback(const int error, const char* desc)
    {
        std::cerr << "GLFW error " << error << ": " << desc << std::endl;
    }

    Window::Window(const std::string& title, const uint32_t width, const uint32_t height, const bool maximize)
        : m_Width(width), m_Height(height)
    {
        if (!glfwInit())
            assert(false);

        glfwSetErrorCallback(GLFWErrorCallback);

        m_GLFWwindow = glfwCreateWindow(static_cast<int>(m_Width), static_cast<int>(m_Height), title.c_str(), nullptr, nullptr);
        if (!m_GLFWwindow)
        {
            glfwTerminate();
            assert(false);
        }

        glfwMakeContextCurrent(m_GLFWwindow);

        if (maximize)
            glfwMaximizeWindow(m_GLFWwindow);

        glfwSetWindowUserPointer(m_GLFWwindow, this);

        RegisterCallbacks();
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::ShouldClose() const
    {
        return glfwWindowShouldClose(m_GLFWwindow);
    }

    void Window::SetShouldClose(const bool value) const
    {
        glfwSetWindowShouldClose(m_GLFWwindow, value);
    }

    void Window::PollEvents()
    {
        glfwPollEvents();
    }

    void Window::RegisterCallbacks() const
    {
        // Window
        glfwSetWindowCloseCallback(m_GLFWwindow, [](GLFWwindow* window)
        {
            if (const auto* win = static_cast<Window*>(glfwGetWindowUserPointer(window)); win->m_EventCallback)
            {
                WindowClosedEvent event;
                win->m_EventCallback(event);
            }
        });

        glfwSetWindowSizeCallback(m_GLFWwindow, [](GLFWwindow* window, const int width, const int height)
        {
            if (auto* win = static_cast<Window*>(glfwGetWindowUserPointer(window)); win->m_EventCallback)
            {
                WindowResizedEvent event(width, height);
                win->m_Width = width; // Setting window width and height here.
                win->m_Height = height;
                win->m_EventCallback(event);
            }
        });

        // Key
        glfwSetKeyCallback(m_GLFWwindow, [](GLFWwindow* window, const int key, const int scancode, const int action, const int mods)
        {
            if (const auto* win = static_cast<Window*>(glfwGetWindowUserPointer(window)); win->m_EventCallback)
            {
                if (action == GLFW_PRESS)
                {
                    KeyPressedEvent event(static_cast<Keycode>(key));
                    win->m_EventCallback(event);
                }
                else if (action == GLFW_RELEASE)
                {
                    KeyReleasedEvent event(static_cast<Keycode>(key));
                    win->m_EventCallback(event);
                }
            }
        });

        // Mouse
        glfwSetMouseButtonCallback(m_GLFWwindow, [](GLFWwindow* window, const int button, const int action, const int mods)
        {
            if (const auto* win = static_cast<Window*>(glfwGetWindowUserPointer(window)); win->m_EventCallback)
            {
                if (action == GLFW_PRESS)
                {
                    MouseButtonPressedEvent event(static_cast<MouseButton>(button));
                    win->m_EventCallback(event);
                }
                else if (action == GLFW_RELEASE)
                {
                    MouseButtonReleasedEvent event(static_cast<MouseButton>(button));
                    win->m_EventCallback(event);
                }
            }
        });

        glfwSetCursorPosCallback(m_GLFWwindow, [](GLFWwindow* window, const double xpos, const double ypos)
        {
            if (const auto* win = static_cast<Window*>(glfwGetWindowUserPointer(window)); win->m_EventCallback)
            {
                MouseMovedEvent event(xpos, ypos);
                win->m_EventCallback(event);
            }
        });

        glfwSetScrollCallback(m_GLFWwindow, [](GLFWwindow* window, const double xoffset, const double yoffset)
        {
            if (const auto* win = static_cast<Window*>(glfwGetWindowUserPointer(window)); win->m_EventCallback)
            {
                MouseScrolledEvent event(xoffset, yoffset);
                win->m_EventCallback(event);
            }
        });
    }
}
