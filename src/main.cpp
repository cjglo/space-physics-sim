#include "main.hpp"

#include "Renderer.hpp"

int main() {
    const int screenWidth = 1700;
    const int screenHeight = 1000;
    auto world = world::World{screenWidth, screenHeight};
    auto renderer = render::Renderer{screenWidth, screenHeight, world};

    while (!renderer.windowShouldClose()) {
        renderer.beginDrawing();
        renderer.clearBackground(BLACK);
        UserInput::handleUserInput(world);
        world.updateObjects();
        renderer.drawObjects();
        renderer.endDrawing();
    }

    return 0;
}