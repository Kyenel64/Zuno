//
// Created by Kye Nelson on 10/16/25.
//

#include <iostream>

#include "Engine/Event.h"
#include "Engine/Window.h"

// Temp
void OnEvent(Event& event)
{
    switch (event.GetType())
    {
    case EventType::WindowClose:
        {
            std::cout << "WindowClosedEvent" << std::endl;
            break;
        }
    case EventType::WindowResize:
        {
            const auto* e = dynamic_cast<WindowResizedEvent*>(&event);
            std::cout << "WindowResizedEvent: " << "w: " << e->GetWidth() << "h: " << e->GetHeight() << std::endl;
            break;
        }
    case EventType::KeyPressed:
        {
            const auto* e = dynamic_cast<KeyPressedEvent*>(&event);
            std::cout << "KeyPressedEvent: " << "key: " << e->GetKey() << std::endl;
            break;
        }
    case EventType::KeyReleased:
        {
            const auto* e = dynamic_cast<KeyReleasedEvent*>(&event);
            std::cout << "KeyReleasedEvent: " << "key: " << e->GetKey() << std::endl;
            break;
        }
    default:
        break;
    }
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
