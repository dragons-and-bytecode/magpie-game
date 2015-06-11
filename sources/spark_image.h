#pragma once

#include "base.h"
#include "context_store.h"

typedef struct {
    context_id context;
    Vector2D size;
} Image;

Image* spark_create_image_from_file_in_display(
        const char* filename,
        const Display* display);

void spark_image_prepare_for_rendering(
    const Image* image,
    const Display* display);

void spark_display_immidiately(const Image* image);
