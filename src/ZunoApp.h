//
// Created by Kye Nelson on 10/24/25.
//

#pragma once

#include <ZunoEngine.h>

class ZunoApp
{
public:
    explicit ZunoApp(std::string title, uint32_t width, uint32_t height);
    ~ZunoApp();

    void Run();

    void LoadScript(std::filesystem::path entrypoint);

    void OnEvent(Zuno::Event& event);

private:
    void RegisterAPI() const;
    void RegisterScriptFunctions() const;

private:
    std::string m_Title;
    std::filesystem::path m_Entrypoint;

    Zuno::Window* m_Window = nullptr;
    Zuno::ScriptEngine* m_ScriptEngine = nullptr;
};
