//
// Created by Kye Nelson on 10/21/25.
//

#include "core/ZunoPCH.h"
#include "ScriptEngine.h"

namespace Zuno
{
    static sol::protected_function_result LuaErrorHandler(lua_State* state, sol::protected_function_result result)
    {
        const sol::error err = result;
        ZUNO_ERROR("Lua Error: {0}", err.what());
        return result;
    }

    ScriptEngine::ScriptEngine(std::string nameSpace)
        : m_Namespace(std::move(nameSpace))
    {
        m_Lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::table, sol::lib::string);
        m_Lua[m_Namespace] = m_Lua.create_table();
    }


    bool ScriptEngine::LoadScript(const std::filesystem::path& path)
    {
        sol::protected_function_result result = m_Lua.safe_script_file(path.string(), LuaErrorHandler);

        if (!result.valid())
            return false;
        return true;
    }

    bool ScriptEngine::LoadScriptString(const std::string& script)
    {
        sol::protected_function_result result = m_Lua.safe_script(script, LuaErrorHandler);

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
