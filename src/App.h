#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
} AppWindowData;

enum AppStates {
    MainMenu,
    InGame,
    Paused,
    Idle
};

void appInit(AppWindowData *app);
void appQuit(AppWindowData *app);