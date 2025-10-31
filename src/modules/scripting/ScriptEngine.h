//
// Created by Kye Nelson on 10/21/25.
//

#pragma once

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "modules/scene/Entity.h"


namespace Zuno
{
    template<typename T>
    struct UserType
    {
        sol::usertype<T> Type;
        std::string ClassName;

        template<typename Func>
        void SetPropertyReadOnly(const std::string& propName, Func prop)
        {
            Type.set(propName, sol::readonly_property(prop));
        }

        template<typename Func>
        void SetFunction(const std::string& propName, Func prop)
        {
            Type.set(propName, prop);
        }
    };


    class ScriptEngine
    {
    public:
        explicit ScriptEngine(std::string nameSpace);

        sol::state& GetState() { return m_Lua; }

        bool LoadScript(const std::filesystem::path& path, Entity entity);
        bool LoadScriptString(const std::string& script);
        void RegisterScriptFunction(const std::string& funcName);

        template<typename T>
        UserType<T> RegisterClassType(const std::string& name)
        {
            sol::usertype type =  m_Lua.new_usertype<T>(name);
            return { type, name };
        }

        template <typename... Args>
        bool CallFunction(const std::string& funcName, Args&&... args)
        {
            if (!m_CachedFunctions[funcName].valid())
                return false;
            m_CachedFunctions[funcName](std::forward<Args>(args)...);
            return true;
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
