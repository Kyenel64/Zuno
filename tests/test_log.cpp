//
// Created by Kye Nelson on 10/20/25.
//

#include <gtest/gtest.h>
#include <ZunoEngine.h>

TEST(Log, LogPrimitives)
{
    const char* str = "Hello world";
    Zuno::Log::Init();
    ZUNO_INFO(1);
    ZUNO_TRACE("Hello world");
    ZUNO_WARN(true);
    ZUNO_WARN(str);
}

TEST(Log, LogEnums)
{
    ZUNO_INFO(Zuno::Keycode::A);
    ZUNO_TRACE(Zuno::MouseButton::Left);
    ZUNO_WARN(Zuno::Keycode::Space);
    ZUNO_ERROR(Zuno::MouseButton::Middle);
}
