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
        explicit Engine(std::string windowTitle, uint32_t width, uint32_t height);
        ~Engine();

        void Run() const;

        void LoadEntrypoint(std::filesystem::path scriptPath);

        void OnEvent(Event& event);

    private:
        void RegisterAPI() const;
        void RegisterScriptFunctions() const;

    private:
        std::string m_WindowTitle;
        std::filesystem::path m_Entrypoint;
        Entity m_Root;

        Window* m_Window = nullptr;
        ScriptEngine* m_ScriptEngine = nullptr;
        Scene* m_Scene = nullptr;
    };
}
