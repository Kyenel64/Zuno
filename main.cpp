// --- main.cpp (test) ---
// Created by Kye Nelson on 6/23/25.
// Entrypoint for testing Zuno API.
#include "Engine.h"
#include "Window.h"
#include "Graphics/Graphics.h"
#include "BaseGame.h"
#include "Graphics/Texture.h"
#include "Graphics/ImageData.h"

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

        Engine.GetGraphics().DrawTexture(m_TestTexture);
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
};

int main()
{
    Zuno::Engine engine;
    TestGame game(engine);

    game.Run();
}
