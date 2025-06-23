//
// Created by Kye Nelson on 6/23/25.
//

#include "Engine.h"
#include "BaseGame.h"
#include <iostream>

class TestGame : public Zuno::BaseGame
{
public:
    explicit TestGame(Zuno::Engine& engine) : Zuno::BaseGame(engine) {}
    ~TestGame() = default;

    void OnLoad() override {}
    void OnUpdate() override {}

    void OnDraw() override
    {
        Engine.GetGraphics().DrawPoint(100, 100);
        Engine.GetGraphics().DrawLine(100, 100, 200, 200);
    }

    void OnKeyPressed(Zuno::KeyCode key) override
    {
        if (key == Zuno::KEY_W)
            std::cout << "W Pressed";
    }
};

int main()
{
    Zuno::Engine engine;
    TestGame game(engine);

    game.Run();
}
