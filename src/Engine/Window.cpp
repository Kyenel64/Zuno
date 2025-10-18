//
// Created by Kye Nelson on 10/17/25.
//

#include "Window.h"

#include <cassert>
#include <iostream>
#include <GLFW/glfw3.h>

#include "Event.h"

static void GLFWErrorCallback(int error, const char* desc)
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

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::RegisterCallbacks() const
{
    glfwSetWindowCloseCallback(m_GLFWwindow, [](GLFWwindow* window)
    {
        if (const auto* win = static_cast<Window*>(glfwGetWindowUserPointer(window)); win->m_EventCallback)
        {
            WindowClosedEvent event;
            win->m_EventCallback(event);
        }
    });
}
