// --- main.cpp (test) ---
// Created by Kye Nelson on 6/23/25.
// Entrypoint for testing Zuno API.
#include "Engine.h"
#include "Window.h"
#include "Graphics/Graphics.h"
#include "BaseGame.h"
#include "Graphics/Texture.h"
#include "Graphics/ImageData.h"
#include "Graphics/Rect.h"

#include <glm/glm.hpp>

#include <iostream>

class TestGame : public Zuno::BaseGame
{
public:
    explicit TestGame(Zuno::Engine& engine) : Zuno::BaseGame(engine) {}
    ~TestGame() override = default;

    void OnLoad() override
    {
        Engine.GetWindow().SetTitle("TestGame");

        m_TestTexture = Engine.GetGraphics().CreateTexture("../sample.png");
        m_Icon = Engine.GetGraphics().CreateImageData("../icon.png");
        m_Rect = Engine.GetGraphics().CreateRect(0, 0, 2000, 2000);

        Engine.GetWindow().SetIcon(m_Icon);

        std::cout << Engine.GetWindow().GetDesktopSize().x << std::endl;
    }

    void OnUpdate() override
    {
    }

    void OnDraw() override
    {
        Engine.GetGraphics().DrawPoint(100, 100);
        Engine.GetGraphics().DrawLine(100, 100, 200, 200);

        Engine.GetGraphics().Draw(*m_TestTexture, *m_Rect, { Engine.GetWindow().GetSize().x / 2, Engine.GetWindow().GetSize().y / 2 }, 45, { 300, 300 }, { 150, 150});
    }

    void OnQuit() override
    {
        delete m_TestTexture;
    }

    void OnKeyPressed(Zuno::KeyCode key) override
    {
        if (key == Zuno::KEY_W)
            Engine.GetWindow().SetFullscreen(!Engine.GetWindow().IsFullscreen());
    }

private:
    Zuno::Texture* m_TestTexture = nullptr;
    Zuno::ImageData* m_Icon = nullptr;
    Zuno::Rect* m_Rect = nullptr;
};

int main()
{
    Zuno::Engine engine;
    TestGame game(engine);

    game.Run();
}
