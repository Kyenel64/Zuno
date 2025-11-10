//
// Created by Kye Nelson on 10/24/25.
//

#include "Engine.h"

constexpr double MS_PER_UPDATE = 1000.0f / 60.0f; // 60 FPS

namespace Zuno
{
    Engine::Engine(std::string windowTitle, const uint32_t width, const uint32_t height)
        : m_WindowTitle(std::move(windowTitle))
    {
        Log::Init();

        m_Window = new Window(m_WindowTitle, width, height);

        m_ScriptEngine = new ScriptEngine("zuno");
        RegisterAPI();

        m_Scene = new Scene(m_ScriptEngine);
        m_Root = m_Scene->CreateEntity("Root");

        m_Window->SetEventCallback([&](Event& e) { OnEvent(e); });

        ZUNO_INFO("Zuno initialized");
    }

    Engine::~Engine()
    {
        delete m_Scene;
        delete m_ScriptEngine;
        delete m_Window;
        ZUNO_INFO("ZunoEngine shutdown");
    }

    void Engine::LoadEntrypoint(std::filesystem::path scriptPath)
    {
        m_EntrypointPath = std::move(scriptPath);
        m_Scene->AddComponent<ScriptComponent>(m_Root, m_EntrypointPath);
    }


    void Engine::Run() const
    {
        m_Scene->OnLoad();

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
                m_Scene->OnFixedUpdate();
                lag -= MS_PER_UPDATE;
                updateCount++;
            }

            // Update
            m_Scene->OnUpdate(elapsed);

            // Draw
            // double alpha = lag / 16; TODO: Alpha interpolate
            m_Scene->OnDraw();
        }
        m_Scene->OnQuit();
    }

    void Engine::OnEvent(Event& event)
    {
        m_Scene->OnEvent(event);
    }

    void Engine::RegisterAPI() const
    {
        // Global
        m_ScriptEngine->RegisterAPI("quit", [this]() { m_Window->SetShouldClose(true); });
        m_ScriptEngine->RegisterAPI("wait", [](const int seconds) { std::this_thread::sleep_for(std::chrono::seconds(seconds));});
        m_ScriptEngine->RegisterAPI("create", [this](const std::string& name, const std::string& pathToScript)
        {
            const Entity entity = m_Scene->CreateEntity(name);
            if (!pathToScript.empty())
            {
                m_Scene->AddComponent<ScriptComponent>(entity, pathToScript);
                // Not sure if I should call load here. Maybe better to wait for next loop to call load before the updates?
                m_ScriptEngine->CallEnvFunction("load", m_Scene->GetComponent<ScriptComponent>(entity).Env);
            }

            ZUNO_TRACE("Created entity '{0}'", name);
            return entity;
        });
        m_ScriptEngine->RegisterAPI("window.should_close", [this]() { return m_Window->ShouldClose(); });

        // Entity
        UserType<Entity> entity = m_ScriptEngine->RegisterClassType<Entity>("Entity", sol::no_constructor);
        entity.SetPropertyReadOnly("handle", &Entity::GetHandle);
        entity.SetPropertyReadOnly("name", [this](Entity& self) { return m_Scene->GetComponent<TagComponent>(self).Tag; });
        entity.SetFunction("get_component", [this](Entity& self, const std::string& componentName)
        {
            if (componentName == "tag")
                return sol::make_object(m_ScriptEngine->GetState(), m_Scene->GetComponent<TagComponent>(self));

            return sol::make_object(m_ScriptEngine->GetState(), sol::lua_nil);
        });

        UserType<TagComponent> tagComponent = m_ScriptEngine->RegisterClassType<TagComponent>("TagComponent", sol::no_constructor);
        tagComponent.SetPropertyReadOnly("tag", &TagComponent::Tag);
    }
}
