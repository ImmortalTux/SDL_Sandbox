#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>
#include <SDL_ttf.h>

#include "App.h"

int main() {
    AppWindowData app;

    appInit(&app);

    SDL_Surface *bmpSurface = SDL_LoadBMP("./res/");

    const char* texts[] = {"Play", "Blank", "Quit"};
    int textCounter = 0;
    TTF_Font *font = TTF_OpenFont("../res/DroidSans.ttf", 12);
    SDL_Color fontColor = {255, 255, 255, 255};
    SDL_Surface *switchingText = TTF_RenderText_Solid(font, texts[0], fontColor);
    SDL_Texture *switchingTextTexture = SDL_CreateTextureFromSurface(app.renderer, switchingText);
    SDL_Rect textBounds = {10, 10, 100, 25};

    SDL_Event eventLoop;
    while (app.running) {
        SDL_RenderClear(app.renderer);

        switch(app.currentState) {
            case MainMenu:

                break;

            default:
                break;
        }

        SDL_RenderPresent(app.renderer);
    }

    SDL_FreeSurface(bmpSurface);
    SDL_FreeSurface(switchingText);

    appQuit(&app);
    return 0;
}