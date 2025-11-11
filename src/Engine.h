//
// Created by Kye Nelson on 10/24/25.
//

#pragma once

#include <ZunoEngine.h>

namespace Zuno
{
    class Engine
    {
    public:
        Engine(std::string windowTitle, uint32_t width, uint32_t height);
        ~Engine();

        void Run();

        void LoadEntrypoint(std::filesystem::path scriptPath);

        void OnEvent(Event& event);

    private:
        void RegisterAPI();

    private:
        std::string m_WindowTitle;
        std::filesystem::path m_EntrypointPath;
        Entity m_Root;

        // In order
        Window m_Window;
        ScriptEngine m_ScriptEngine;
        Scene m_Scene;
    };
}
