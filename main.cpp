//
// Created by Kye Nelson on 10/16/25.
//

#include <iostream>

#include "ZunoEngine.h"

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
    case EventType::MouseButtonPressed:
        {
            const auto* e = dynamic_cast<MouseButtonPressedEvent*>(&event);
            std::cout << "MouseButtonPressedEvent: " << "mouseButton: " << e->GetMouseButton() << std::endl;
            break;
        }
    case EventType::MouseButtonReleased:
        {
            const auto* e = dynamic_cast<MouseButtonReleasedEvent*>(&event);
            std::cout << "MouseButtonReleasedEvent: " << "mouseButton: " << e->GetMouseButton() << std::endl;
            break;
        }
    case EventType::MouseMoved:
        {
            const auto* e = dynamic_cast<MouseMovedEvent*>(&event);
            std::cout << "MouseMovedEvent: " << "X: " << e->GetXPos() << "Y: " << e->GetYPos() << std::endl;
            break;
        }
    case EventType::MouseScrolled:
        {
            const auto* e = dynamic_cast<MouseScrolledEvent*>(&event);
            std::cout << "MouseMovedEvent: " << "X: " << e->GetXOffset() << "Y: " << e->GetYOffset() << std::endl;
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

    while (!window.ShouldClose())
    {
        window.PollEvents();

        // Update()
        // Render()
    }
}
