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

        // Implicit conversion
        operator uint32_t() const { return static_cast<uint32_t>(m_Handle); }

    protected:
        explicit Entity(const entt::entity handle): m_Handle(handle) {}

    private:
        entt::entity m_Handle = entt::null;

    public:
        friend class Scene;
    };
}
