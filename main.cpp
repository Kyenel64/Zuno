//
// Created by Kye Nelson on 6/23/25.
//

#include "Engine.h"
#include "BaseGame.h"
#include "Graphics/Texture.h"
#include <iostream>

class TestGame : public Zuno::BaseGame
{
public:
    explicit TestGame(Zuno::Engine& engine) : Zuno::BaseGame(engine) {}
    ~TestGame() override = default;

    void OnLoad() override
    {
        Engine.GetWindow().SetTitle("TestGame");
        std::cout << Engine.GetWindow().GetTitle() << std::endl;;
        std::cout << Engine.GetWindow().GetPosition().x << std::endl;
        m_TestTexture = Engine.GetGraphics().CreateTexture("../sample.png");
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
            std::cout << "W Pressed";
    }

private:
    Zuno::Texture* m_TestTexture = nullptr;
};

int main()
{
    Zuno::Engine engine;
    TestGame game(engine);

    game.Run();
}
