//
// Created by Kye Nelson on 10/19/25.
//

#pragma once

#include <ostream>

namespace Zuno
{
    enum class MouseButton: int
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

    inline std::ostream& operator<<(std::ostream& os, MouseButton mouseButton)
    {
        return os << static_cast<int>(mouseButton);
    }
}
