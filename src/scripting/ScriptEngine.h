//
// Created by Kye Nelson on 10/21/25.
//

#pragma once

#include <filesystem>
#include <vector>

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>


namespace Zuno
{
    class ScriptEngine
    {
    public:
        explicit ScriptEngine(std::string nameSpace);

        sol::state& GetState() { return m_Lua; }

        bool LoadScript(const std::filesystem::path& path);
        void RegisterScriptFunction(const std::string& funcName);

        template <typename... Args>
        void CallFunction(const std::string& funcName, Args&&... args)
        {
            m_CachedFunctions[funcName](std::forward<Args>(args)...);
        }

        template <typename Func>
        void RegisterAPI(const std::string& funcName, Func&& func)
        {
            // TODO: assert valid function name

            // Dissect funcName. Eg. "window.close' = ['window', 'close']
            std::vector<std::string> parts;
            std::string segment;
            std::stringstream ss(funcName);
            while (std::getline(ss, segment, '.'))
                parts.push_back(segment);

            // Parse tables. Create table if necessary.
            sol::table currentTable = m_Lua[m_Namespace].get<sol::table>();
            for (size_t i = 0; i + 1 < parts.size(); i++)
            {
                const std::string& tableName = parts[i];
                if (!currentTable[tableName].valid())
                    currentTable[tableName] = m_Lua.create_table();
                currentTable = currentTable[tableName].get<sol::table>();
            }

            const std::string& functionName = parts.back();
            currentTable[functionName] = std::forward<Func>(func);
        }

    private:
        std::string m_Namespace;
        sol::state m_Lua;
        std::unordered_map<std::string, sol::protected_function> m_CachedFunctions;
    };
}
