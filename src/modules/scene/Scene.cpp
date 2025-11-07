//
// Created by Kye Nelson on 10/29/25.
//

#include "core/ZunoPCH.h"
#include "Scene.h"

#include "Components.h"
#include "modules/scripting/ScriptEngine.h"

namespace Zuno
{
    Entity Scene::CreateEntity(const std::string& name)
    {
        const auto entity = Entity(m_Registry.create());
        AddComponent<TagComponent>(entity, name);
        return entity;
    }

    void Scene::OnLoad()
    {
        const auto view = m_Registry.view<ScriptComponent>();
        view.each([this](const ScriptComponent& script)
        {
            m_ScriptEngine->CallEnvFunction("load", script.Env);
        });
    }

    void Scene::OnFixedUpdate()
    {
        const auto view = m_Registry.view<ScriptComponent>();
        view.each([this](const ScriptComponent& script)
        {
            m_ScriptEngine->CallEnvFunction("fixed_update", script.Env);
        });
    }

    void Scene::OnUpdate(double deltaTime)
    {
        const auto view = m_Registry.view<ScriptComponent>();
        view.each([this, deltaTime](const ScriptComponent& script)
        {
            m_ScriptEngine->CallEnvFunction("update", script.Env, deltaTime);
        });
    }

    void Scene::OnDraw()
    {
        const auto view = m_Registry.view<ScriptComponent>();
        view.each([this](const ScriptComponent& script)
        {
            m_ScriptEngine->CallEnvFunction("draw", script.Env);
        });
    }

    void Scene::OnQuit()
    {
        const auto view = m_Registry.view<ScriptComponent>();
        view.each([this](const ScriptComponent& script)
        {
            m_ScriptEngine->CallEnvFunction("on_quit", script.Env);
        });
    }

    void Scene::OnEvent(Event& event)
    {
        const auto view = m_Registry.view<ScriptComponent>();
        switch (event.GetType())
        {
        case EventType::WindowResize:
            {
                if (const auto* e = dynamic_cast<WindowResizedEvent*>(&event))
                {
                    view.each([this, e](const ScriptComponent& script)
                    {
                        m_ScriptEngine->CallEnvFunction("resize", script.Env, e->GetWidth(), e->GetHeight());
                    });
                }
                break;
            }
        case EventType::KeyPressed:
            {
                if (const auto* e = dynamic_cast<KeyPressedEvent*>(&event))
                {
                    view.each([this, e](const ScriptComponent& script)
                    {
                        m_ScriptEngine->CallEnvFunction("key_pressed", script.Env, e->GetKey());
                    });
                }
                break;
            }
        case EventType::KeyReleased:
            {
                if (const auto* e = dynamic_cast<KeyReleasedEvent*>(&event))
                {
                    view.each([this, e](const ScriptComponent& script)
                    {
                        m_ScriptEngine->CallEnvFunction("key_released", script.Env, e->GetKey());
                    });
                }
                break;
            }
        case EventType::MouseButtonPressed:
            {
                if (const auto* e = dynamic_cast<MouseButtonPressedEvent*>(&event))
                {
                    view.each([this, e](const ScriptComponent& script)
                    {
                        m_ScriptEngine->CallEnvFunction("mouse_pressed", script.Env, e->GetMouseButton());
                    });
                }
                break;
            }
        case EventType::MouseButtonReleased:
            {
                if (const auto* e = dynamic_cast<MouseButtonReleasedEvent*>(&event))
                {
                    view.each([this, e](const ScriptComponent& script)
                    {
                        m_ScriptEngine->CallEnvFunction("mouse_released", script.Env, e->GetMouseButton());
                    });
                }
                break;
            }
        case EventType::MouseMoved:
            {
                if (const auto* e = dynamic_cast<MouseMovedEvent*>(&event))
                {
                    view.each([this, e](const ScriptComponent& script)
                    {
                        m_ScriptEngine->CallEnvFunction("mouse_moved", script.Env, e->GetXPos(), e->GetYPos());
                    });
                }
                break;
            }
        case EventType::MouseScrolled:
            {
                if (const auto* e = dynamic_cast<MouseScrolledEvent*>(&event))
                {
                    view.each([this, e](const ScriptComponent& script)
                    {
                        m_ScriptEngine->CallEnvFunction("mouse_scrolled", script.Env, e->GetXOffset(), e->GetYOffset());
                    });
                }
                break;
            }
        default:
            break;
        }
    }
}
