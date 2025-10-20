//
// Created by Kye Nelson on 10/20/25.
//

#pragma once

#include <spdlog/spdlog.h>

namespace Zuno
{
    class Log
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define ZUNO_INFO(...) ::Zuno::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZUNO_TRACE(...) ::Zuno::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZUNO_WARN(...) ::Zuno::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZUNO_ERROR(...) ::Zuno::Log::GetCoreLogger()->error(__VA_ARGS__)

