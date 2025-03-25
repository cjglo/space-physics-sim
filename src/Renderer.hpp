#pragma once
#include <raylib.h>
#include <stdint.h>
#include "World.hpp"
#include "RuleOfFive.hpp"
#include <vector>

namespace render {

using SpaceObject = world::World::SpaceObject;

class Renderer : RuleOfFive {
public:
    Renderer(int screenWidth, int screenHeight, world::World& world) : screenWidth(screenWidth), screenHeight(screenHeight), world(world) {
        InitWindow(screenWidth, screenHeight, "Space Simulator");
        SetTargetFPS(60);
    }

    void drawObjects();

    inline bool windowShouldClose() {
        return WindowShouldClose();
    }

    inline void beginDrawing() {
        BeginDrawing();
    }

    inline void clearBackground(Color color) {
        ClearBackground(color);
    }

    inline void endDrawing() {
        EndDrawing();
    }

    ~Renderer() {
        CloseWindow();
    }


    private:
    const int screenWidth;
    const int screenHeight;
    world::World& world;
};

}  // namespace matter