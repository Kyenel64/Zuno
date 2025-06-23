//
// Created by Kye Nelson on 6/23/25.
//
#pragma once

#include <SDL3/SDL_log.h>

#define ZUNO_ASSERT(expression, ...) if (expression == false) SDL_Log(__VA_ARGS__)
#define ZUNO_LOG(...) SDL_Log(__VA_ARGS__)
