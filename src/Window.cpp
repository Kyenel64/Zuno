//
// Created by Kye Nelson on 6/22/25.
//

#include "Window.h"

namespace Zuno
{
    Window::Window()
    {
        bool success = true;
        if (SDL_Init(SDL_INIT_VIDEO) == false)
        {
            printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            SDLWindow = SDL_CreateWindow("Test", 1920, 1080, 0);
            if (SDLWindow == nullptr)
            {
                printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                SDLSurface = SDL_GetWindowSurface(SDLWindow);
            }
        }
    }
}
