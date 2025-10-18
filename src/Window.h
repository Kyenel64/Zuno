//
// Created by Kye Nelson on 10/17/25.
//

#pragma once

#include <GLFW/glfw3.h>

class Window
{
public:
    Window();
    ~Window();

    bool ShouldClose() const;

    void PollEvents();

private:
    GLFWwindow* m_GLFWwindow = nullptr;
};
