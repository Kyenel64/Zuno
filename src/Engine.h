// --- Engine ---
// Created by Kye Nelson on 6/21/25.
// Main application class for Zuno
#pragma once

#include "Window.h"

namespace Zuno
{
    class Engine
    {
    public:
        Engine();
        ~Engine() {};

    private:
        Window Window;
    };
}
