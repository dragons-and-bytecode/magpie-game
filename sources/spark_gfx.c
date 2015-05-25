#include "spark.h"
#include "base.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

void spark_init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
}

void spark_open_window(Display* display){

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
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}
