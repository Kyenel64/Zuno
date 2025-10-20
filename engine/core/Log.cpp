//
// Created by Kye Nelson on 10/20/25.
//

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Zuno
{
    std::shared_ptr<spdlog::logger> Log::s_Logger;

    void Log::Init()
    {
        if (spdlog::get("ZUNO"))
            return;
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_Logger = spdlog::stdout_color_mt("ZUNO");
        s_Logger->set_level(spdlog::level::trace);
    }

}
