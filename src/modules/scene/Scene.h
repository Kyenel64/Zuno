//
// Created by Kye Nelson on 10/29/25.
//

#pragma once

#include <entt/entt.hpp>

#include "modules/scene/Entity.h"

namespace Zuno
{
    class Scene
    {
    public:
        Scene();
        ~Scene() = default;

        Entity CreateEntity(const std::string& name = "entity");

        Entity GetRootEntity() const { return m_Root; }

        template<typename T, typename... Args>
        T& AddComponent(Entity entity, Args&&... args)
        {
            T& component = m_Registry.emplace<T>(static_cast<entt::entity>(entity), std::forward<Args>(args)...);
            return component;
        }

        template<typename T>
        T& GetComponent(Entity entity)
        {
            return m_Registry.get<T>(static_cast<entt::entity>(entity));
        }

        template<typename T>
        [[nodiscard]] bool HasComponent(Entity entity) const
        {
            return m_Registry.any_of<T>(static_cast<entt::entity>(entity));
        }

        template<typename T>
        void RemoveComponent(Entity entity)
        {
            m_Registry.remove<T>(static_cast<entt::entity>(entity));
        }
    private:
        entt::registry m_Registry;
        Entity m_Root;
    };
}
