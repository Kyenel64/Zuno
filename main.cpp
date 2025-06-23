//
// Created by Kye Nelson on 6/23/25.
//

#include "Engine.h"
#include "BaseGame.h"

class TestGame : public Zuno::BaseGame
{
public:
    explicit TestGame(Zuno::Engine& engine) : Zuno::BaseGame(engine) {}
    ~TestGame() = default;

    void OnLoad() override {}
    void OnUpdate() override {}
    void OnDraw() override {}


    void OnKeyPressed(int key) override {}
};

int main()
{
    Zuno::Engine engine;
    TestGame game(engine);

    game.Run();
}
