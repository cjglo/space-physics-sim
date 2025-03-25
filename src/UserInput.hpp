#pragma once
#include <raylib.h>
#include <vector>
#include "World.hpp"

namespace UserInput {

void handleUserInput(world::World& world) {
    auto& objects = world.objects;
    // check if mouse is clicked
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        auto x = GetMouseX();
        auto y = GetMouseY();
        objects.emplace_back(world::World::SpaceObject{x, y, 1.0});
    }
}

}  // namespace UserInput