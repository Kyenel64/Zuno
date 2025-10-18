//
// Created by Kye Nelson on 10/18/25.
//

#pragma once
#include "../Core/Keycode.h"

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


// Window events
class WindowClosedEvent final : public Event
{
public:
    WindowClosedEvent() = default;
    [[nodiscard]] EventType GetType() const override { return EventType::WindowClose; }
};

class WindowResizedEvent final : public Event
{
public:
    WindowResizedEvent(const uint32_t width, const uint32_t height) : m_Width(width), m_Height(height) {}
    [[nodiscard]] EventType GetType() const override { return EventType::WindowResize; }

    [[nodiscard]] uint32_t GetWidth() const { return m_Width; }
    [[nodiscard]] uint32_t GetHeight() const { return m_Height; }
private:
    uint32_t m_Width, m_Height;
};

// Key events
class KeyPressedEvent final : public Event
{
public:
    KeyPressedEvent(const Keycode key) : m_Key(key) {}
    [[nodiscard]] EventType GetType() const override { return EventType::KeyPressed; }

    [[nodiscard]] Keycode GetKey() const { return m_Key; }
public:
    Keycode m_Key;
};

class KeyReleasedEvent final : public Event
{
public:
    KeyReleasedEvent(const Keycode key) : m_Key(key) {}
    [[nodiscard]] EventType GetType() const override { return EventType::KeyReleased; }

    [[nodiscard]] Keycode GetKey() const { return m_Key; }
public:
    Keycode m_Key;
};
