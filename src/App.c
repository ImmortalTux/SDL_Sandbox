#include "App.h"

void appInit(AppWindowData *app) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    app->window = SDL_CreateWindow(
            "Sokoban C!",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN
    );

    if (app->window == NULL) { printf("%s\n", SDL_GetError()); return; }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (app->renderer == NULL) { printf("%s\n", SDL_GetError()); return; }

    app->running = true;
    app->currentState = MainMenu;
}

void appQuit(AppWindowData *app) {
    app->running = false;

    SDL_DestroyRenderer(app->renderer);
    SDL_DestroyWindow(app->window);
    SDL_Quit();
    TTF_Quit();
}