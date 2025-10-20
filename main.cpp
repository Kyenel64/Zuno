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
            ZUNO_INFO("WindowClosedEvent");
            break;
        }
    case Zuno::EventType::WindowResize:
        {
            const auto* e = dynamic_cast<Zuno::WindowResizedEvent*>(&event);
            ZUNO_TRACE("WindowResizedEvent: w: {0}, h: {1}", e->GetWidth(), e->GetHeight());
            break;
        }
    case Zuno::EventType::KeyPressed:
        {
            const auto* e = dynamic_cast<Zuno::KeyPressedEvent*>(&event);
            ZUNO_TRACE("KeyPressedEvent: key: {0}", e->GetKey());
            break;
        }
    case Zuno::EventType::KeyReleased:
        {
            const auto* e = dynamic_cast<Zuno::KeyReleasedEvent*>(&event);
            ZUNO_TRACE("KeyReleasedEvent: key: {0}", e->GetKey());
            break;
        }
    case Zuno::EventType::MouseButtonPressed:
        {
            const auto* e = dynamic_cast<Zuno::MouseButtonPressedEvent*>(&event);
            ZUNO_TRACE("MouseButtonPressedEvent: mouseButton: {0}", e->GetMouseButton());
            break;
        }
    case Zuno::EventType::MouseButtonReleased:
        {
            const auto* e = dynamic_cast<Zuno::MouseButtonReleasedEvent*>(&event);
            ZUNO_TRACE("MouseButtonReleasedEvent: mouseButton: {0}", e->GetMouseButton());
            break;
        }
    case Zuno::EventType::MouseScrolled:
        {
            const auto* e = dynamic_cast<Zuno::MouseScrolledEvent*>(&event);
            ZUNO_TRACE("MouseScrolledEvent: x: {0}, y: {1}", e->GetXOffset(), e->GetYOffset());
            break;
        }
    default:
        break;
    }
}

int main()
{
    // 1. Initialize subsystems (window, graphics, lua, console, etc.)
    // 2. Gameloop
    // 3. Destroy

    Zuno::Log::Init();
    ZUNO_INFO("Welcome to Zuno!");
    ZUNO_INFO("Info");
    ZUNO_TRACE("Trace");
    ZUNO_WARN("Warn");
    ZUNO_ERROR("Error");

    Zuno::Window window("Zuno", 640, 480);
    window.SetEventCallback(OnEvent);

    while (!window.ShouldClose())
    {
        window.PollEvents();

        // Update()
        // Render()
    }
}
