#include "Renderer.hpp"

namespace render {

void Renderer::drawSpace() {
    for (const auto &object : world.objects) {
        DrawCircle(object.x, object.y, object.radius, WHITE);
    }
    drawMenusAndInfo();
}

void Renderer::drawMenusAndInfo() {
    if (world.isPaused) {
        const int SPACE_BETWEEN_PAUSE_LINES = 30;
        DrawRectangle(cornerOfScreenX, cornerOfScreenY, 20, 100, RED);
        DrawRectangle(cornerOfScreenX + SPACE_BETWEEN_PAUSE_LINES, cornerOfScreenY, 20, 100, RED);
    }
}

}  // namespace render