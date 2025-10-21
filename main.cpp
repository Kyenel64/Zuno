//
// Created by Kye Nelson on 10/16/25.
//

#include <iostream>
#include <filesystem>

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "ZunoEngine.h"

int main(int argc, char* argv[])
{
    std::filesystem::path entrypointPath;
    if (argc == 2)
    {
        entrypointPath = argv[1];
        entrypointPath = std::filesystem::weakly_canonical(std::filesystem::current_path() / entrypointPath);
        if (!std::filesystem::exists(entrypointPath))
        {
            std::cerr << "Zuno: Cannot find file at: " << entrypointPath.c_str() << std::endl;
            return 1;
        }
    }

    Zuno::Log::Init();
    ZUNO_INFO("Welcome to Zuno!");

    Zuno::Window window("Zuno", 640, 480);

    // Load Lua API
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    lua["zuno"] = lua.create_table_with(
        "quit", [&]() { window.SetShouldClose(true); }
    );

    lua["zuno"]["window"] = lua.create_table_with(
        "is_open", [&]() { return !window.ShouldClose(); }
    );

    const sol::function loadFn = lua["zuno"]["load"];
    const sol::function updateFn = lua["zuno"]["update"];
    const sol::function drawFn = lua["zuno"]["draw"];

    window.SetEventCallback([&](Zuno::Event& event)
    {
        if (event.GetType() == Zuno::EventType::KeyPressed)
        {
            const sol::function keyPressedFn = lua["zuno"]["key_pressed"];
            const auto* e = dynamic_cast<Zuno::KeyPressedEvent*>(&event);
            keyPressedFn(e->GetKey());
        }
    });

    lua.script_file(entrypointPath);

    loadFn();

    while (!window.ShouldClose())
    {
        window.PollEvents();
        updateFn(10);
        drawFn();
    }
}
