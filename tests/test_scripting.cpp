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

TEST(Scripting, RegisterAPI)
{
    Zuno::ScriptEngine scriptEngine("zuno");
    scriptEngine.RegisterAPI("test", []() { return 100; });
    constexpr int x = 30;
    scriptEngine.RegisterAPI("test_capture", [x]() { return x; });
}

TEST(Scripting, LoadScript)
{
    Zuno::ScriptEngine scriptEngine("zuno");

    EXPECT_TRUE("test.lua"); // Make sure test.lua exist in bin directory
    EXPECT_FALSE(scriptEngine.LoadScript("invalidScriptFile.txt"));
    EXPECT_FALSE(scriptEngine.LoadScript("invalidScriptFile.lua"));

}

TEST(Scripting, LoadScriptString)
{
    Zuno::ScriptEngine scriptEngine("zuno");

    EXPECT_TRUE(scriptEngine.LoadScriptString("print('test')"));
    EXPECT_TRUE(scriptEngine.LoadScriptString("")); // Empty strings are valid.
    EXPECT_FALSE(scriptEngine.LoadScriptString("print(")); // Catch invalid lua
}

TEST(Scripting, CallScriptFunction)
{
    Zuno::ScriptEngine scriptEngine("zuno");

    EXPECT_FALSE(scriptEngine.CallFunction("non_existing_function"));
}

TEST(Scripting, ScriptFile_Integration)
{
    Zuno::ScriptEngine scriptEngine("zuno");

    scriptEngine.RegisterAPI("test", []() { return "Test: ScriptFile_Integration"; });
    EXPECT_TRUE(scriptEngine.LoadScript("test.lua"));
    scriptEngine.RegisterScriptFunction("testFn");
    EXPECT_TRUE(scriptEngine.CallFunction("testFn"));
}

TEST(Scripting, ScriptString_Integration)
{
    Zuno::ScriptEngine scriptEngine("zuno");

    scriptEngine.RegisterAPI("test", []() { return "Test: ScriptString_Integration"; });
    EXPECT_TRUE(scriptEngine.LoadScriptString("function zuno.testFn() print(zuno.test()) end"));
    scriptEngine.RegisterScriptFunction("testFn");
    EXPECT_TRUE(scriptEngine.CallFunction("testFn"));
}
