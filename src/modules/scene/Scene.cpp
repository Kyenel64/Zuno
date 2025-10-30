//
// Created by Kye Nelson on 10/29/25.
//

#include "core/ZunoPCH.h"
#include "Scene.h"

namespace Zuno
{
    Entity Scene::CreateEntity()
    {
        const entt::entity entity = m_Registry.create();
        return Entity(entity);
    }
}
