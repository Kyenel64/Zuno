//
// Created by Kye Nelson on 10/30/25.
//

#pragma once

#include <string>
#include <filesystem>
#include <sol/environment.hpp>

namespace Zuno
{
    struct TagComponent
    {
        std::string Tag;

        TagComponent() = default;
        explicit TagComponent(std::string tag) : Tag(std::move(tag)) {}
        TagComponent(const TagComponent&) = default;
    };

    struct ScriptComponent
    {
        std::filesystem::path Path;
        sol::environment Env;

        explicit ScriptComponent(std::filesystem::path path)
            : Path(std::move(path)) {}

        ScriptComponent(const ScriptComponent&) = default;
    };
}
