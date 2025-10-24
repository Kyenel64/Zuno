//
// Created by Kye Nelson on 10/24/25.
//

#include "ZunoApp.h"

ZunoApp::ZunoApp(std::string title, const uint32_t width, const uint32_t height)
    : m_Title(std::move(title))
{
    Zuno::Log::Init();
    m_Window = new Zuno::Window(m_Title, width, height);
    m_ScriptEngine = new Zuno::ScriptEngine("zuno");

    RegisterAPI();

    m_Window->SetEventCallback([&](Zuno::Event& e) { OnEvent(e); });

    ZUNO_INFO("Zuno initialized");
}

ZunoApp::~ZunoApp()
{
    delete m_ScriptEngine;
    delete m_Window;
    ZUNO_INFO("ZunoEngine shutdown");
}

void ZunoApp::LoadScript(std::filesystem::path entrypoint)
{
    m_Entrypoint = std::move(entrypoint);
    m_ScriptEngine->LoadScript(m_Entrypoint);
    RegisterScriptFunctions();
}


void ZunoApp::Run()
{
    m_ScriptEngine->CallFunction("load");
    while (!m_Window->ShouldClose())
    {
        m_Window->PollEvents();
        m_ScriptEngine->CallFunction("update");
        m_ScriptEngine->CallFunction("draw");
    }
    m_ScriptEngine->CallFunction("on_quit");
}

void ZunoApp::OnEvent(Zuno::Event& event)
{
    switch (event.GetType())
    {
    case Zuno::EventType::WindowResize:
        {
            if (const auto* e = dynamic_cast<Zuno::WindowResizedEvent*>(&event))
                m_ScriptEngine->CallFunction("resize", e->GetWidth(), e->GetHeight());
            break;
        }
    case Zuno::EventType::KeyPressed:
        {
            if (const auto* e = dynamic_cast<Zuno::KeyPressedEvent*>(&event))
                m_ScriptEngine->CallFunction("key_pressed", e->GetKey());
            break;
        }
    case Zuno::EventType::KeyReleased:
        {
            if (const auto* e = dynamic_cast<Zuno::KeyReleasedEvent*>(&event))
                m_ScriptEngine->CallFunction("key_released", e->GetKey());
            break;
        }
    case Zuno::EventType::MouseButtonPressed:
        {
            if (const auto* e = dynamic_cast<Zuno::MouseButtonPressedEvent*>(&event))
                m_ScriptEngine->CallFunction("mouse_pressed", e->GetMouseButton());
            break;
        }
    case Zuno::EventType::MouseButtonReleased:
        {
            if (const auto* e = dynamic_cast<Zuno::MouseButtonReleasedEvent*>(&event))
                m_ScriptEngine->CallFunction("mouse_released", e->GetMouseButton());
            break;
        }
    case Zuno::EventType::MouseMoved:
        {
            if (const auto* e = dynamic_cast<Zuno::MouseMovedEvent*>(&event))
                m_ScriptEngine->CallFunction("mouse_moved", e->GetXPos(), e->GetYPos());
            break;
        }
    case Zuno::EventType::MouseScrolled:
        {
            if (const auto* e = dynamic_cast<Zuno::MouseScrolledEvent*>(&event))
                m_ScriptEngine->CallFunction("mouse_scrolled", e->GetXOffset(), e->GetYOffset());
            break;
        }
    default:
        break;
    }
}

void ZunoApp::RegisterAPI() const
{
    m_ScriptEngine->RegisterAPI("quit", [this]() { m_Window->SetShouldClose(true); });
    m_ScriptEngine->RegisterAPI("window.should_close", [this]() { return m_Window->ShouldClose(); });
}

void ZunoApp::RegisterScriptFunctions() const
{
    m_ScriptEngine->RegisterScriptFunction("load");
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
