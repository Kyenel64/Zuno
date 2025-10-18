//
// Created by Kye Nelson on 10/18/25.
//

#pragma once

enum class EventType
{
    None = 0,
    WindowClose, WindowResize,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

class Event
{
public:
    virtual ~Event() = default;
    [[nodiscard]] virtual EventType GetType() const = 0;

public:
    bool handled = false;
};

class WindowClosedEvent final : public Event
{
public:
    WindowClosedEvent() = default;
    [[nodiscard]] EventType GetType() const override { return EventType::WindowClose; }
};
