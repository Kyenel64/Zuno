//
// Created by Kye Nelson on 11/10/25.
//
#include <gtest/gtest.h>
#include <ZunoEngine.h>

TEST(Scene, CreateEntity)
{
    Zuno::Scene scene;
    Zuno::Entity entity = scene.CreateEntity();
    Zuno::Entity nullEntity;
    EXPECT_NE(entity, nullEntity);

    Zuno::Entity namedEntity = scene.CreateEntity("Test Entity");
    EXPECT_EQ(scene.GetComponent<Zuno::TagComponent>(namedEntity).Tag, "Test Entity");
}

TEST(Scene, BasicComponentOperations)
{
    Zuno::Scene scene;
    Zuno::Entity entity = scene.CreateEntity();
    scene.AddComponent<Zuno::ScriptComponent>(entity, "/test/path");

    EXPECT_EQ(scene.GetComponent<Zuno::ScriptComponent>(entity).Path, "/test/path");
    EXPECT_TRUE(scene.HasComponent<Zuno::ScriptComponent>(entity));

    scene.RemoveComponent<Zuno::ScriptComponent>(entity);
    EXPECT_FALSE(scene.HasComponent<Zuno::ScriptComponent>(entity));
}
