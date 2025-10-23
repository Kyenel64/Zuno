//
// Created by Kye Nelson on 10/16/25.
//

#include <iostream>
#include <filesystem>

#include <ZunoEngine.h>

#define RED "\033[31m"

static void PrintUsage()
{
    std::cout << "Usage: \n" << std::endl;
    std::cout << "  zuno <path-to-scene-file>" << std::endl;
    std::cout << "\n";
    std::cout << "Specify a lua file as an entrypoint to your game." << std::endl;
}

static void ProcessArgs(int argc, char* argv[], int& retValue, std::filesystem::path& entryPath)
{
    if (argc <= 1)
    {
        std::cerr << RED << "Zuno error: no lua file provided. Use --help for list of commands" << std::endl;
        retValue = 1;
        return;
    }
    if (strcmp(argv[1], "--help") == 0)
    {
        PrintUsage();
        retValue = 0;
        return;
    }
    entryPath = argv[1];
    entryPath = std::filesystem::weakly_canonical(std::filesystem::current_path() / entryPath);
    if (!std::filesystem::exists(entryPath))
    {
        std::cerr << RED << "Zuno error: Cannot find file at: " << entryPath << std::endl;
        retValue = 1;
        return;
    }
    if (entryPath.extension() != ".lua")
    {
        std::cerr << RED << "Zuno error: Entrypoint must be a .lua file: " << entryPath << std::endl;
        retValue = 1;
        return;
    }
}

int main(int argc, char* argv[])
{
    // --- Process args ---
    std::filesystem::path entrypointPath;
    int retValue = -1;
    ProcessArgs(argc, argv, retValue, entrypointPath);
    if (retValue != -1)
        return retValue;

    // --- Init subsystems ---
    Zuno::Log::Init();
    Zuno::Window window("Zuno", 640, 480);
    ZUNO_INFO("ZunoEngine initialized");


    // --- Init lua API ---
    Zuno::ScriptEngine scriptEngine("zuno");

    scriptEngine.RegisterAPI("quit", [&]() { window.SetShouldClose(true); });
    scriptEngine.RegisterAPI("window.should_close", [&]() { return window.ShouldClose(); });

    scriptEngine.LoadScript(entrypointPath);

    scriptEngine.RegisterScriptFunction("load");
    scriptEngine.RegisterScriptFunction("update");
    scriptEngine.RegisterScriptFunction("draw");
    scriptEngine.RegisterScriptFunction("on_quit");
    scriptEngine.RegisterScriptFunction("resize");
    scriptEngine.RegisterScriptFunction("key_pressed");
    scriptEngine.RegisterScriptFunction("key_released");
    scriptEngine.RegisterScriptFunction("mouse_pressed");
    scriptEngine.RegisterScriptFunction("mouse_released");
    scriptEngine.RegisterScriptFunction("mouse_moved");
    scriptEngine.RegisterScriptFunction("mouse_scrolled");

    window.SetEventCallback([&](Zuno::Event& event)
    {
        switch (event.GetType())
        {
        case Zuno::EventType::WindowResize:
            {
                if (const auto* e = dynamic_cast<Zuno::WindowResizedEvent*>(&event))
                    scriptEngine.CallFunction("resize", e->GetWidth(), e->GetHeight());
                break;
            }
        case Zuno::EventType::KeyPressed:
            {
                if (const auto* e = dynamic_cast<Zuno::KeyPressedEvent*>(&event))
                    scriptEngine.CallFunction("key_pressed", e->GetKey());
                break;
            }
        case Zuno::EventType::KeyReleased:
            {
                if (const auto* e = dynamic_cast<Zuno::KeyReleasedEvent*>(&event))
                    scriptEngine.CallFunction("key_released", e->GetKey());
                break;
            }
        case Zuno::EventType::MouseButtonPressed:
            {
                if (const auto* e = dynamic_cast<Zuno::MouseButtonPressedEvent*>(&event))
                    scriptEngine.CallFunction("mouse_pressed", e->GetMouseButton());
                break;
            }
        case Zuno::EventType::MouseButtonReleased:
            {
                if (const auto* e = dynamic_cast<Zuno::MouseButtonReleasedEvent*>(&event))
                    scriptEngine.CallFunction("mouse_released", e->GetMouseButton());
                break;
            }
        case Zuno::EventType::MouseMoved:
            {
                if (const auto* e = dynamic_cast<Zuno::MouseMovedEvent*>(&event))
                    scriptEngine.CallFunction("mouse_moved", e->GetXPos(), e->GetYPos());
                break;
            }
        case Zuno::EventType::MouseScrolled:
            {
                if (const auto* e = dynamic_cast<Zuno::MouseScrolledEvent*>(&event))
                    scriptEngine.CallFunction("mouse_scrolled", e->GetXOffset(), e->GetYOffset());
                break;
            }
        default:
            break;
        }
    });

    ZUNO_INFO("Script Engine initialized");


    // --- Main loop ---
    scriptEngine.CallFunction("load");
    while (!window.ShouldClose())
    {
        window.PollEvents();
        scriptEngine.CallFunction("update");
        scriptEngine.CallFunction("draw");
    }
    scriptEngine.CallFunction("on_quit");

    return 0;
}
