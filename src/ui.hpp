#ifndef UI_HPP
#define UI_HPP

#include <SDL2/SDL.h>

namespace UI {
    bool init(SDL_Renderer* renderer);     // Load assets, setup
    void handleEvent(const SDL_Event& e);  // Mouse / keyboard events
    void update();                         // Animation, logic
    void render(SDL_Renderer* renderer);   // Draw everything
    void shutdown();                       // Cleanup
}

#endif // UI_HPP
