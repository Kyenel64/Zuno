//
// Created by Kye Nelson on 10/19/25.
//

#pragma once

#include "spdlog/fmt/bundled/base.h"

namespace Zuno
{
    enum MouseButton: int
    {
        Button0 = 0,
        Button1 = 1,
        Button2 = 2,
        Button3 = 3,
        Button4 = 4,
        Button5 = 5,
        Button6 = 6,
        Button7 = 7,

        Last = Button7,
        Left = Button0,
        Right = Button1,
        Middle = Button2
    };

}

template <>
struct fmt::formatter<Zuno::MouseButton> : fmt::formatter<int>
{
    auto format(const Zuno::MouseButton mouseButton, fmt::format_context& ctx) const
    {
        return formatter<int>::format(mouseButton, ctx);
    }
};
