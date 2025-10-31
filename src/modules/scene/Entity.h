//
// Created by Kye Nelson on 10/30/25.
//

#pragma once

#include <entt/entt.hpp>

namespace Zuno
{
    class Entity
    {
    public:
        Entity() = delete;
        ~Entity() = default;
        Entity(const Entity&) = default;

        uint32_t GetHandle() const { return static_cast<uint32_t>(m_Handle); }

        // Implicit conversion
        explicit operator uint32_t() const { return static_cast<uint32_t>(m_Handle); }
        explicit operator entt::entity() const { return static_cast<entt::entity>(m_Handle); }

    protected:
        explicit Entity(const entt::entity handle): m_Handle(handle) {}

    private:
        entt::entity m_Handle{entt::null};

        friend class Scene;
    };
}
