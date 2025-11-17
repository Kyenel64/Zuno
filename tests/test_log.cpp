//
// Created by Kye Nelson on 10/20/25.
//

#include <gtest/gtest.h>
#include <ZunoEngine.h>

TEST(Log, LogPrimitives)
{
    const char* str = "Hello world";
    testing::internal::CaptureStdout();
    ZUNO_INFO(1);
    ZUNO_TRACE("Hello world");
    ZUNO_WARN(true);
    ZUNO_WARN(str);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.contains("ZUNO: 1"));
    EXPECT_TRUE(output.contains("ZUNO: Hello world"));
    EXPECT_TRUE(output.contains("ZUNO: true"));
    EXPECT_TRUE(output.contains("ZUNO: Hello world"));
}

TEST(Log, LogEnums)
{
    testing::internal::CaptureStdout();
    ZUNO_INFO(Zuno::Keycode::A);
    ZUNO_TRACE(Zuno::MouseButton::Left);
    ZUNO_WARN(Zuno::Keycode::Space);
    ZUNO_ERROR(Zuno::MouseButton::Middle);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.contains(fmt::format("ZUNO: ", Zuno::Keycode::A)));
    EXPECT_TRUE(output.contains(fmt::format("ZUNO: ", Zuno::MouseButton::Left)));
    EXPECT_TRUE(output.contains(fmt::format("ZUNO: ", Zuno::Keycode::Space)));
    EXPECT_TRUE(output.contains(fmt::format("ZUNO: ", Zuno::MouseButton::Middle)));
}
