#include "World.hpp"

namespace world {

void World::updateSpace() {
    // erase destroyed objects
    objects.erase(std::remove_if(objects.begin(), objects.end(),
                                 [](const SpaceObject& obj) { return obj.mass == 0; }),
                  objects.end());

    // Don't update anything after this point if world is paused
    if (isPaused) {
        return;
    }

    handleObjectVelocityAndGravity();
}

void World::handleObjectVelocityAndGravity() {
    // go far enough and you'll come back
    static constexpr auto ROOM_FOR_ERROR_FOR_LOCATION = 8;
    for (auto& object : objects) {
        if (object.x < -ROOM_FOR_ERROR_FOR_LOCATION) {
            object.x = screenWidth - ROOM_FOR_ERROR_FOR_LOCATION;
        }
        if (object.x > screenWidth + ROOM_FOR_ERROR_FOR_LOCATION) {
            object.x = ROOM_FOR_ERROR_FOR_LOCATION;
        }
        if (object.y < -ROOM_FOR_ERROR_FOR_LOCATION) {
            object.y = screenHeight - ROOM_FOR_ERROR_FOR_LOCATION;
        }
        if (object.y > screenHeight + ROOM_FOR_ERROR_FOR_LOCATION) {
            object.y = ROOM_FOR_ERROR_FOR_LOCATION;
        }
    }

    for (auto& object : objects) {
        for (auto& object2 : objects) {
            if (&object == &object2) {
                continue;
            }
            // Collision
            if (sqrt(pow(object2.x - object.x, 2) + pow(object2.y - object.y, 2)) <
                object.radius + object2.radius + 10) {
                object.xVelocity =
                    (object.xVelocity * object.mass + object2.xVelocity * object2.mass) /
                    (object.mass + object2.mass);
                object.yVelocity =
                    (object.yVelocity * object.mass + object2.yVelocity * object2.mass) /
                    (object.mass + object2.mass);
                object.x = (object.x * object.mass + object2.x * object2.mass) /
                           (object.mass + object2.mass);
                object.y = (object.y * object.mass + object2.y * object2.mass) /
                           (object.mass + object2.mass);
                object.mass += object2.mass;
                object2.mass = 0;
                auto obj1SurfaceArea = object.getSurfaceArea();
                auto obj2SurfaceArea = object2.getSurfaceArea();
                object.radius = sqrt((obj1SurfaceArea + obj2SurfaceArea) / PI);
            }

            if (object2.mass == 0 || object.mass == 0) {
                continue;
            }

            auto distance = sqrt(pow(object2.x - object.x, 2) + pow(object2.y - object.y, 2));
            auto force = CalculateForceOfGravity(object.mass, object2.mass, distance);

            auto xForce = ((object2.x - object.x) / distance) * force;
            auto yForce = ((object2.y - object.y) / distance) * force;

            auto xAcceleration = xForce / object.mass;
            auto yAcceleration = yForce / object.mass;

            object.xVelocity += xAcceleration;
            object.yVelocity += yAcceleration;
        }
        object.x += object.xVelocity;
        object.y += object.yVelocity;
    }
}

}  // namespace world