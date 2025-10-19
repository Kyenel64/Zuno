//
// Created by Kye Nelson on 10/18/25.
//

#pragma once

#include "input/Key.h"
#include "input/MouseButton.h"

namespace Zuno
{
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
        explicit KeyPressedEvent(const Keycode key) : m_Key(key) {}
        [[nodiscard]] EventType GetType() const override { return EventType::KeyPressed; }

        [[nodiscard]] Keycode GetKey() const { return m_Key; }
    public:
        Keycode m_Key;
    };

    class KeyReleasedEvent final : public Event
    {
    public:
        explicit KeyReleasedEvent(const Keycode key) : m_Key(key) {}
        [[nodiscard]] EventType GetType() const override { return EventType::KeyReleased; }

        [[nodiscard]] Keycode GetKey() const { return m_Key; }
    public:
        Keycode m_Key;
    };


    // Mouse events
    class MouseButtonPressedEvent final : public Event
    {
    public:
        explicit MouseButtonPressedEvent(const MouseButton key) : m_MouseButton(key) {}
        [[nodiscard]] EventType GetType() const override { return EventType::MouseButtonPressed; }

        [[nodiscard]] MouseButton GetMouseButton() const { return m_MouseButton; }
    public:
        MouseButton m_MouseButton;
    };

    class MouseButtonReleasedEvent final : public Event
    {
    public:
        explicit MouseButtonReleasedEvent(const MouseButton key) : m_MouseButton(key) {}
        [[nodiscard]] EventType GetType() const override { return EventType::MouseButtonReleased; }

        [[nodiscard]] MouseButton GetMouseButton() const { return m_MouseButton; }
    public:
        MouseButton m_MouseButton;
    };

    class MouseMovedEvent final : public Event
    {
    public:
        MouseMovedEvent(const double x, const double y) : m_XPos(x), m_YPos(y) {}
        [[nodiscard]] EventType GetType() const override { return EventType::MouseMoved; }

        [[nodiscard]] double GetXPos() const { return m_XPos; }
        [[nodiscard]] double GetYPos() const { return m_YPos; }
    public:
        double m_XPos, m_YPos;
    };

    class MouseScrolledEvent final : public Event
    {
    public:
        MouseScrolledEvent(const double xOffset, const double yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}
        [[nodiscard]] EventType GetType() const override { return EventType::MouseScrolled; }

        [[nodiscard]] double GetXOffset() const { return m_XOffset; }
        [[nodiscard]] double GetYOffset() const { return m_YOffset; }
    public:
        double m_XOffset, m_YOffset;
    };
}
