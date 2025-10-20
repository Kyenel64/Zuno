//
// Created by Kye Nelson on 10/19/25.
//

#include <gtest/gtest.h>
#include <ZunoEngine.h>

#ifdef ZUNO_CI
GTEST_SKIP()
#endif
TEST(Window, WindowEventCallback)
{
    bool callBackTriggered = false;
    Zuno::Window window("TestCallback", 640, 480);
    window.SetEventCallback([&](Zuno::Event& e)
    {
        callBackTriggered = true;
        EXPECT_EQ(e.GetType(), Zuno::EventType::WindowClose);
    });

    Zuno::WindowClosedEvent e;
    window.DispatchEvent(e);

    EXPECT_TRUE(callBackTriggered);
}

TEST(Window, WindowShouldClose)
{
    Zuno::Window window("TestClose", 640, 480);

    EXPECT_FALSE(window.ShouldClose());

    window.SetShouldClose(true);
    EXPECT_TRUE(window.ShouldClose());
}
