#include "spark.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Image* spark_create_image_from_file_in_display(
        const char* filename,
        const Display* display){

    Image* image = malloc(sizeof(image));
    image->context = create_context();

    SDL_Surface* surface = IMG_Load(filename);
    image->size.x = surface->w;
    image->size.y = surface->h;

    SDL_Renderer* renderer = context_read(display->context, "renderer", NULL);
    SDL_Window*   window   = context_read(display->context, "window", NULL);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(
        renderer,
        surface
    );

    context_write(image->context, "texture", texture);
    context_write(image->context, "renderer", renderer);
    context_write(image->context, "window", window);

    SDL_FreeSurface(surface);

    return image;
}

void spark_display_immidiately(const Image* image){
    SDL_Renderer* renderer = context_read(image->context, "renderer", NULL);
    SDL_Window*   window   = context_read(image->context, "window", NULL);
    SDL_Texture*  texture  = context_read(image->context, "texture", NULL);

    int screen_w, screen_h;
    SDL_GL_GetDrawableSize(window, &screen_w, &screen_h);


    SDL_Rect destination = {
        .x = screen_w / 2 - image->size.x / 2,
        .y = screen_h / 2 - image->size.y / 2,
        .w = image->size.x,
        .h = image->size.y
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer,texture,NULL,&destination);

    SDL_RenderPresent(renderer);
}
