//
// Created by Kye Nelson on 10/19/25.
//

#include <gtest/gtest.h>
#include <ZunoEngine.h>

TEST(Window, WindowEventCallback)
{
    bool callBackTriggered = false;
    Window window("TestCallback", 640, 480);
    window.SetEventCallback([&](Event& e)
    {
        callBackTriggered = true;
        EXPECT_EQ(e.GetType(), EventType::WindowClose);
    });

    WindowClosedEvent e;
    window.DispatchEvent(e);

    EXPECT_TRUE(callBackTriggered);
}

TEST(Window, WindowShouldClose)
{
    Window window("TestClose", 640, 480);

    EXPECT_FALSE(window.ShouldClose());

    window.SetShouldClose(true);
    EXPECT_TRUE(window.ShouldClose());
}
