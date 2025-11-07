//
// Created by Kye Nelson on 10/29/25.
//

#pragma once

#include <entt/entt.hpp>

#include "modules/scripting/ScriptEngine.h"
#include "modules/event/Event.h"
#include "modules/scene/Entity.h"
#include "modules/scene/Components.h"

namespace Zuno
{
    class Scene
    {
    public:
        explicit Scene(ScriptEngine* scriptEngine) : m_ScriptEngine(scriptEngine) {}
        ~Scene() = default;

        Entity CreateEntity(const std::string& name = "entity");

        void OnLoad();
        void OnEvent(Event& event);
        void OnFixedUpdate();
        void OnUpdate(double deltaTime);
        void OnDraw();
        void OnQuit();

        template<typename T, typename... Args>
        T& AddComponent(const Entity entity, Args&&... args)
        {
            T& component = m_Registry.emplace<T>(static_cast<entt::entity>(entity), std::forward<Args>(args)...);

            if constexpr (std::is_same_v<T, ScriptComponent>)
            {
                component.Env = m_ScriptEngine->LoadScript(component.Path, entity);
            }
            return component;
        }

        template<typename T>
        T& GetComponent(const Entity entity)
        {
            return m_Registry.get<T>(static_cast<entt::entity>(entity));
        }

        template<typename T>
        [[nodiscard]] bool HasComponent(const Entity entity) const
        {
            return m_Registry.any_of<T>(static_cast<entt::entity>(entity));
        }

        template<typename T>
        void RemoveComponent(const Entity entity)
        {
            m_Registry.remove<T>(static_cast<entt::entity>(entity));
        }
    private:
        entt::registry m_Registry;

        ScriptEngine* m_ScriptEngine = nullptr;
    };
}
