//
// Created by Kye Nelson on 10/16/25.
//

#include <iostream>

#include "ZunoEngine.h"

// Temp
void OnEvent(Zuno::Event& event)
{
    switch (event.GetType())
    {
    case Zuno::EventType::WindowClose:
        {
            std::cout << "WindowClosedEvent" << std::endl;
            break;
        }
    case Zuno::EventType::WindowResize:
        {
            const auto* e = dynamic_cast<Zuno::WindowResizedEvent*>(&event);
            std::cout << "WindowResizedEvent: " << "w: " << e->GetWidth() << "h: " << e->GetHeight() << std::endl;
            break;
        }
    case Zuno::EventType::KeyPressed:
        {
            const auto* e = dynamic_cast<Zuno::KeyPressedEvent*>(&event);
            std::cout << "KeyPressedEvent: " << "key: " << e->GetKey() << std::endl;
            break;
        }
    case Zuno::EventType::KeyReleased:
        {
            const auto* e = dynamic_cast<Zuno::KeyReleasedEvent*>(&event);
            std::cout << "KeyReleasedEvent: " << "key: " << e->GetKey() << std::endl;
            break;
        }
    case Zuno::EventType::MouseButtonPressed:
        {
            const auto* e = dynamic_cast<Zuno::MouseButtonPressedEvent*>(&event);
            std::cout << "MouseButtonPressedEvent: " << "mouseButton: " << e->GetMouseButton() << std::endl;
            break;
        }
    case Zuno::EventType::MouseButtonReleased:
        {
            const auto* e = dynamic_cast<Zuno::MouseButtonReleasedEvent*>(&event);
            std::cout << "MouseButtonReleasedEvent: " << "mouseButton: " << e->GetMouseButton() << std::endl;
            break;
        }
    case Zuno::EventType::MouseMoved:
        {
            const auto* e = dynamic_cast<Zuno::MouseMovedEvent*>(&event);
            std::cout << "MouseMovedEvent: " << "X: " << e->GetXPos() << "Y: " << e->GetYPos() << std::endl;
            break;
        }
    case Zuno::EventType::MouseScrolled:
        {
            const auto* e = dynamic_cast<Zuno::MouseScrolledEvent*>(&event);
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

    Zuno::Window window("Zuno", 640, 480);
    window.SetEventCallback(OnEvent);

    while (!window.ShouldClose())
    {
        window.PollEvents();

        // Update()
        // Render()
    }
}
