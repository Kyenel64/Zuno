//
// Created by Kye Nelson on 10/17/25.
//

#include "Window.h"

#include <cassert>

Window::Window()
{
    if (!glfwInit())
        assert(false);

    m_GLFWwindow = glfwCreateWindow(640, 480, "Zuno", nullptr, nullptr);
    if (!m_GLFWwindow)
    {
        glfwTerminate();
        assert(false);
    }

    glfwMakeContextCurrent(m_GLFWwindow);
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
