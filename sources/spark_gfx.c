#include "spark.h"
#include "base.h"

#include <SDL2/SDL.h>

static bool initilized = false;

void spark_open_window(Display* display){
    if (!initilized)
        SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow(
        display->title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        display->resolution.x,
        display->resolution.y,
        0
    );
}

void spark_sleep(double seconds){
    SDL_Delay(seconds * 1000);
}

void spark_shutdown(){
    SDL_Quit();
}
