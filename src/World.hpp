#pragma once
#include <stdint.h>
#include <vector>
#include "RuleOfFive.hpp"
#include "raylib.h"

namespace world {

// Gravity constant
static constexpr auto G = .667430;  // changed by orders of magnitude for the sake of the simulation

class World : RuleOfFive {
   public:
    struct SpaceObject {
        int64_t x;
        int64_t y;
        double radius;
        float xVelocity = 0.0;
        float yVelocity = 0.0;
        int64_t mass = 80;
        double getSurfaceArea() { return PI * radius * radius; };
    };

    World(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) {}

    [[nodiscard]]
    inline int CalculateForceOfGravity(int mass1, int mass2, int distance) {
        return (G * mass1 * mass2) /
               (distance *
                (distance / 10));  // scaling this to make gravity have slightly more affect
                                   // far away and slightly less close up than normal
    }

    [[nodiscard]]
    inline int CalculateAcceleration(int force, int mass) {
        return force / mass;
    }
    void updateObjects();

    std::vector<SpaceObject> objects;

    private:
    const int screenWidth;
    const int screenHeight;
};

}  // namespace world