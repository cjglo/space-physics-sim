#pragma once
#include <raylib.h>
#include <stdint.h>

#include <vector>

#include "RuleOfFive.hpp"
#include "World.hpp"

namespace render {

using SpaceObject = world::World::SpaceObject;

class Renderer : RuleOfFive {
   public:
    Renderer(int screenWidth, int screenHeight, world::World& world)
        : screenWidth(screenWidth),
          screenHeight(screenHeight),
          cornerOfScreenX(screenWidth * 0.9),
          cornerOfScreenY(screenHeight / 10),
          world(world) {
        InitWindow(screenWidth, screenHeight, "Space Simulator");
        SetTargetFPS(60);
    }

    void drawSpace();

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
    void drawMenusAndInfo();

    const int screenWidth;
    const int screenHeight;
    const int cornerOfScreenX;
    const int cornerOfScreenY;
    world::World& world;
};

}  // namespace render