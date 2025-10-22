//
// Created by Kye Nelson on 10/21/25.
//

#include "ScriptEngine.h"

namespace Zuno
{
    ScriptEngine::ScriptEngine(std::string nameSpace)
        : m_Namespace(std::move(nameSpace))
    {
        m_Lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::table, sol::lib::string);
        m_Lua[m_Namespace] = m_Lua.create_table();
    }


    bool ScriptEngine::LoadScript(const std::filesystem::path& path)
    {
        sol::protected_function_result result = m_Lua.safe_script_file(path, &sol::script_pass_on_error);

        if (!result.valid())
        {
            const sol::error err = result;
            std::cerr << "[Lua Error] " << err.what() << "\n";
            return false;
        }

        return true;
    }

    void ScriptEngine::RegisterScriptFunction(const std::string& funcName)
    {
        sol::object obj = m_Lua[m_Namespace][funcName];
        if (obj.is<sol::function>())
            m_CachedFunctions[funcName] = obj.as<sol::protected_function>();
    }
}
