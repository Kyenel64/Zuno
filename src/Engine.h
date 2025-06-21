// -- Engine ---
// Created by Kye Nelson on 6/21/25.
// Main application class for Zuno
#pragma once

#include <iostream>

namespace Zuno
{
    class Engine
    {
    public:
        Engine();
        ~Engine();
    private:
    };

    static void Run()
    {
        while (true)
        {
            std::cout << "Running" << std::endl;
        }
    }
}
