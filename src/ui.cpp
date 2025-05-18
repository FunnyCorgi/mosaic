#include "ui.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

// Globals (private to this file)
namespace {
    SDL_Texture* gateTexture = nullptr;
    SDL_Texture* logoTexture = nullptr;
    TTF_Font* font_SourceCodePro = nullptr;
    TTF_Font* font_PressStart2P = nullptr;

    SDL_Rect gateRect = { 100, 100, 128, 64 };  // initial position + size
    SDL_Rect logoRect = { 20, 20, 300, 100 };   // top-left logo position
}

namespace UI {

    bool init(SDL_Renderer* renderer) {
        // Load gate image
        SDL_Surface* gateSurface = IMG_Load("assets/png/Gate.png");
        if (!gateSurface) {
            std::cerr << "Failed to load Gate.png: " << IMG_GetError() << "\n";
            return false;
        }
        gateTexture = SDL_CreateTextureFromSurface(renderer, gateSurface);
        SDL_FreeSurface(gateSurface);

        // Load logo image
        SDL_Surface* logoSurface = IMG_Load("assets/png/MosaicLogo.png");
        if (!logoSurface) {
            std::cerr << "Failed to load MosaicLogo.png: " << IMG_GetError() << "\n";
            return false;
        }
        logoTexture = SDL_CreateTextureFromSurface(renderer, logoSurface);
        SDL_FreeSurface(logoSurface);

        // Load fonts
        font_PressStart2P = TTF_OpenFont("assets/fonts/PressStart2P.ttf", 12);
        if (!font) {
            std::cerr << "Failed to load font: " << TTF_GetError() << "\n";
            return false;
        }
        font_SourceCodePro = TTF_OpenFont("assets/fonts/SourceCodePro-Regulare", 12);
        if (!font) {
            std::cerr << "Failed to load font: " << TTF_GetError() << "\n";
            return false;
        }
        return true;
    }

    void handleEvent(const SDL_Event& e) {
        // For now, no interaction — we'll handle dragging later
    }

    void update() {
        // Could add animations or state updates later
        this.render();
    }

    void render(SDL_Renderer* renderer) {
        // Draw logo
        if (logoTexture) SDL_RenderCopy(renderer, logoTexture, nullptr, &logoRect);

        // Draw gate
        if (gateTexture) SDL_RenderCopy(renderer, gateTexture, nullptr, &gateRect);

        // Draw label text later here
    }

    void shutdown() {
        if (gateTexture) SDL_DestroyTexture(gateTexture);
        if (logoTexture) SDL_DestroyTexture(logoTexture);
        if (font) TTF_CloseFont(font);
    }
} // namespace UI
