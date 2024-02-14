#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
    int currentState;
} AppWindowData;

enum AppStates {
    MainMenu = 0,
    InGame = 1,
    Paused = 2,
    Idle = 3,
};

void appInit(AppWindowData *app);
void appQuit(AppWindowData *app);