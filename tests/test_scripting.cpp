//
// Created by Kye Nelson on 10/25/25.
//

#include <gtest/gtest.h>
#include <ZunoEngine.h>

TEST(Scripting, Init)
{
    Zuno::ScriptEngine scriptEngine("zuno");
    const sol::state& state = scriptEngine.GetState();
    EXPECT_NE(state.lua_state(), nullptr);
}

TEST(Scripting, LoadScript)
{
    Zuno::ScriptEngine scriptEngine("zuno");
    sol::environment env = scriptEngine.LoadScript("test.lua");
    EXPECT_NE(env, sol::lua_nil);
}

TEST(Scripting, RegisterAPI)
{
    Zuno::ScriptEngine scriptEngine("zuno");
    scriptEngine.RegisterAPI("test", []() { return 100; });
    int x = 30;
    scriptEngine.RegisterAPI("test_capture", [x]() { return x; });
}

