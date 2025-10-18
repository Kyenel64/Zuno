//
// Created by Kye Nelson on 10/16/25.
//

#include <iostream>

#include "Core/Event.h"
#include "Core/Window.h"

// Temp
void OnEvent(const Event& event)
{
    if (event.GetType() == EventType::WindowClose)
        std::cout << "WindowClosedEvent" << std::endl;
}

int main()
{
    std::cout << "Welcome to Zuno!" << std::endl;

    // 1. Initialize subsystems (window, graphics, lua, console, etc.)
    // 2. Gameloop
    // 3. Destroy

    Window window("Zuno", 640, 480);
    window.SetEventCallback(OnEvent);

    bool running = true;
    while (running)
    {
        window.PollEvents();
        if (window.ShouldClose())
            running = false;

        // Update()
        // Render()
    }
}
