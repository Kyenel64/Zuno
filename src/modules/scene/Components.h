//
// Created by Kye Nelson on 10/30/25.
//

#pragma once

#include <string>
#include <filesystem>

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

        explicit ScriptComponent(std::filesystem::path path)
            : Path(std::move(path))
        {
        }
        ScriptComponent(const ScriptComponent&) = default;
    };
}
