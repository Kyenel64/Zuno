//
// Created by Kye Nelson on 10/24/25.
//

#include "Engine.h"

constexpr double MS_PER_UPDATE = 1000.0f / 60.0f; // 60 FPS

namespace Zuno
{
    Engine::Engine(std::string title, const uint32_t width, const uint32_t height)
        : m_Title(std::move(title))
    {
        Log::Init();
        m_Window = new Window(m_Title, width, height);
        m_ScriptEngine = new ScriptEngine("zuno");

        RegisterAPI();

        m_Window->SetEventCallback([&](Event& e) { OnEvent(e); });

        ZUNO_INFO("Zuno initialized");
    }

    Engine::~Engine()
    {
        delete m_ScriptEngine;
        delete m_Window;
        ZUNO_INFO("ZunoEngine shutdown");
    }

    void Engine::LoadScript(std::filesystem::path entrypoint)
    {
        m_Entrypoint = std::move(entrypoint);
        m_ScriptEngine->LoadScript(m_Entrypoint);
        RegisterScriptFunctions();
    }

    void Engine::Run()
    {
        m_ScriptEngine->CallFunction("load");

        using clock = std::chrono::high_resolution_clock;
        auto previous = clock::now();
        double lag = 0.0f;

        while (!m_Window->ShouldClose())
        {
            auto current = clock::now();
            const double elapsed = std::chrono::duration<double, std::milli>(current - previous).count();
            previous = current;
            lag += elapsed;

            // Process input
            m_Window->PollEvents();

            // Fixed update
            int updateCount = 0;
            while (lag >= MS_PER_UPDATE && updateCount < 5)
            {
                m_ScriptEngine->CallFunction("fixed_update");
                lag -= MS_PER_UPDATE;
                updateCount++;
            }

            // Update
            m_ScriptEngine->CallFunction("update", elapsed / 1000.0f);

            // Draw
            // double alpha = lag / 16; TODO: Alpha interpolate
            m_ScriptEngine->CallFunction("draw");
        }
        m_ScriptEngine->CallFunction("on_quit");
    }

    void Engine::OnEvent(Event& event)
    {
        switch (event.GetType())
        {
        case EventType::WindowResize:
            {
                if (const auto* e = dynamic_cast<WindowResizedEvent*>(&event))
                    m_ScriptEngine->CallFunction("resize", e->GetWidth(), e->GetHeight());
                break;
            }
        case EventType::KeyPressed:
            {
                if (const auto* e = dynamic_cast<KeyPressedEvent*>(&event))
                    m_ScriptEngine->CallFunction("key_pressed", e->GetKey());
                break;
            }
        case EventType::KeyReleased:
            {
                if (const auto* e = dynamic_cast<KeyReleasedEvent*>(&event))
                    m_ScriptEngine->CallFunction("key_released", e->GetKey());
                break;
            }
        case EventType::MouseButtonPressed:
            {
                if (const auto* e = dynamic_cast<MouseButtonPressedEvent*>(&event))
                    m_ScriptEngine->CallFunction("mouse_pressed", e->GetMouseButton());
                break;
            }
        case EventType::MouseButtonReleased:
            {
                if (const auto* e = dynamic_cast<MouseButtonReleasedEvent*>(&event))
                    m_ScriptEngine->CallFunction("mouse_released", e->GetMouseButton());
                break;
            }
        case EventType::MouseMoved:
            {
                if (const auto* e = dynamic_cast<MouseMovedEvent*>(&event))
                    m_ScriptEngine->CallFunction("mouse_moved", e->GetXPos(), e->GetYPos());
                break;
            }
        case EventType::MouseScrolled:
            {
                if (const auto* e = dynamic_cast<MouseScrolledEvent*>(&event))
                    m_ScriptEngine->CallFunction("mouse_scrolled", e->GetXOffset(), e->GetYOffset());
                break;
            }
        default:
            break;
        }
    }

    void Engine::RegisterAPI() const
    {
        m_ScriptEngine->RegisterAPI("quit", [this]() { m_Window->SetShouldClose(true); });
        m_ScriptEngine->RegisterAPI("wait", [](const int seconds) { std::this_thread::sleep_for(std::chrono::seconds(seconds));});
        m_ScriptEngine->RegisterAPI("window.should_close", [this]() { return m_Window->ShouldClose(); });
    }

    void Engine::RegisterScriptFunctions() const
    {
        m_ScriptEngine->RegisterScriptFunction("load");
        m_ScriptEngine->RegisterScriptFunction("fixed_update");
        m_ScriptEngine->RegisterScriptFunction("update");
        m_ScriptEngine->RegisterScriptFunction("draw");
        m_ScriptEngine->RegisterScriptFunction("on_quit");
        m_ScriptEngine->RegisterScriptFunction("resize");
        m_ScriptEngine->RegisterScriptFunction("key_pressed");
        m_ScriptEngine->RegisterScriptFunction("key_released");
        m_ScriptEngine->RegisterScriptFunction("mouse_pressed");
        m_ScriptEngine->RegisterScriptFunction("mouse_released");
        m_ScriptEngine->RegisterScriptFunction("mouse_moved");
        m_ScriptEngine->RegisterScriptFunction("mouse_scrolled");
    }
}
