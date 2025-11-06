//
// Created by Kye Nelson on 10/29/25.
//

#include "core/ZunoPCH.h"
#include "Scene.h"

#include "Components.h"

namespace Zuno
{
    Entity Scene::CreateEntity(const std::string& name)
    {
        auto entity = Entity(m_Registry.create());
        AddComponent<TagComponent>(entity, name);
        return entity;
    }
}
