#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>
#include <SDL_ttf.h>

#include "App.h"

int main() {
    AppWindowData app;

    appInit(&app);

    SDL_Surface *testSurface = SDL_LoadBMP("../res/test.bmp");
    SDL_Texture *testTexture = SDL_CreateTextureFromSurface(app.renderer, testSurface);
    SDL_Rect testTextureDimensions = {0, 0, 32, 32};

    TTF_Font *font = TTF_OpenFont("../res/DroidSans.ttf", 12);
    printf("%s\n", TTF_GetError());
    SDL_Color testTextColor = {255, 0, 0, 255};
    SDL_Surface *testTextSurface = TTF_RenderText_Solid(font, "X", testTextColor);
    printf("%s\n", SDL_GetError());
    SDL_Texture *testTextTexture = SDL_CreateTextureFromSurface(app.renderer, testTextSurface);
    printf("%s\n", SDL_GetError());
    SDL_Rect testTextDimensions = {150, 150, 50, 50};

    SDL_Event eventLoop;
    while (app.running) {
        if (SDL_PollEvent(&eventLoop) > 0) {
            switch (eventLoop.type) {
                case SDL_QUIT:
                    app.running = false;
                    break;

                case SDL_KEYDOWN:
                    switch (eventLoop.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            app.running = false;
                            break;
                    }

                    if (eventLoop.key.keysym.sym == SDLK_w) {
                        testTextureDimensions.y -= 32;
                        break;
                    }
                    if (eventLoop.key.keysym.sym == SDLK_a) {
                        testTextureDimensions.x -= 32;
                        break;
                    }
                    if (eventLoop.key.keysym.sym == SDLK_s) {
                        testTextureDimensions.y += 32;
                        break;
                    }
                    if (eventLoop.key.keysym.sym == SDLK_d) {
                        testTextureDimensions.x += 32;
                        break;
                    }

                    if (eventLoop.key.keysym.sym == SDLK_UP) {
                        testTextDimensions.y -= 32;
                        break;
                    }
                    if (eventLoop.key.keysym.sym == SDLK_LEFT) {
                        testTextDimensions.x -= 32;
                        break;
                    }
                    if (eventLoop.key.keysym.sym == SDLK_DOWN) {
                        testTextDimensions.y += 32;
                        break;
                    }
                    if (eventLoop.key.keysym.sym == SDLK_RIGHT) {
                        testTextDimensions.x += 32;
                        break;
                    }

                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&testTextureDimensions.x, &testTextureDimensions.y);
            }
        }

        SDL_RenderClear(app.renderer);

        SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
        SDL_RenderCopy(app.renderer, testTexture, NULL, &testTextureDimensions);

        SDL_RenderCopy(app.renderer, testTextTexture, NULL, &testTextDimensions);

        SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);

        SDL_RenderPresent(app.renderer);
    }

    SDL_FreeSurface(testSurface);
    SDL_FreeSurface(testTextSurface);

    appQuit(&app);
    return 0;
}