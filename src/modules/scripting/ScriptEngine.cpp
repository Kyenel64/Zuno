//
// Created by Kye Nelson on 10/21/25.
//

#include "core/ZunoPCH.h"
#include "ScriptEngine.h"

namespace Zuno
{
    ScriptEngine::ScriptEngine(std::string nameSpace)
        : m_Namespace(std::move(nameSpace))
    {
        m_Lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::table, sol::lib::string);
        m_Lua[m_Namespace] = m_Lua.create_table();
    }


    bool ScriptEngine::LoadScript(const std::filesystem::path& path, Entity entity)
    {
        sol::environment env(m_Lua, sol::create, m_Lua.globals());
        env["self"] = entity;

        const sol::load_result chunk = m_Lua.load_file(path.string());
        if (!chunk.valid())
        {
            sol::error err = chunk;
            ZUNO_ERROR("Failed to load script '{0}': {1}", path.string(), err.what());
            return false;
        }

        const sol::protected_function func = chunk;

        sol::set_environment(env, func);

        const sol::protected_function_result result = func();
        if (!result.valid())
        {
            sol::error err = result;
            ZUNO_ERROR("Failed to run script '{0}': {1}", path.string(), err.what());
            return false;
        }

        return true;
    }

    bool ScriptEngine::LoadScriptString(const std::string& script)
    {
        sol::protected_function_result result = m_Lua.safe_script(script);

        if (!result.valid())
            return false;
        return true;
    }

    void ScriptEngine::RegisterScriptFunction(const std::string& funcName)
    {
        sol::object obj = m_Lua[m_Namespace][funcName];
        if (obj.is<sol::function>())
            m_CachedFunctions[funcName] = obj.as<sol::protected_function>();
    }
}
