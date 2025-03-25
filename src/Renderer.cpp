#include "Renderer.hpp"

namespace render {

void Renderer::drawObjects() {
    for (const auto &object : world.objects) {
        DrawCircle(object.x, object.y, object.radius, WHITE);
    }
}

}  // namespace render