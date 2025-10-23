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

        static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
    private:
        static std::shared_ptr<spdlog::logger> s_Logger;
    };
}

#define ZUNO_INFO(...) ::Zuno::Log::GetLogger()->info(__VA_ARGS__)
#define ZUNO_TRACE(...) ::Zuno::Log::GetLogger()->trace(__VA_ARGS__)
#define ZUNO_WARN(...) ::Zuno::Log::GetLogger()->warn(__VA_ARGS__)
#define ZUNO_ERROR(...) ::Zuno::Log::GetLogger()->error(__VA_ARGS__)

