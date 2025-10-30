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
        Scene() = default;
        ~Scene() = default;

        Entity CreateEntity();
    private:
        entt::registry m_Registry;
    };
}
