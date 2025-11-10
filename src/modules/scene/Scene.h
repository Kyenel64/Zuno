//
// Created by Kye Nelson on 10/29/25.
//

#pragma once

#include <entt/entt.hpp>

#include "modules/scene/Entity.h"
#include "modules/scene/Components.h"

namespace Zuno
{
    class Scene
    {
    public:
        explicit Scene() = default;
        ~Scene() = default;

        Entity CreateEntity(const std::string& name = "entity");

        template<typename... Components, typename Func>
        void View(Func func)
        {
            auto view = m_Registry.view<Components...>();
            view.each(func);
        }

        template<typename T, typename... Args>
        T& AddComponent(const Entity entity, Args&&... args)
        {
            return m_Registry.emplace<T>(static_cast<entt::entity>(entity), std::forward<Args>(args)...);
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
    };
}
