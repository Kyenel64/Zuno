//
// Created by Kye Nelson on 10/16/25.
//

#include <iostream>

#include "Window.h"

int main()
{
    std::cout << "Welcome to Zuno!" << std::endl;

    // 1. Initialize subsystems
    // 2. Create lua vm
    // 3. Gameloop
    // 4. Destroy

    auto window = Window();

    while (!window.ShouldClose())
    {
        window.PollEvents();
    }
}
