#ifndef __SPARK_H__
#define __SPARK_H__

#include "base.h"

typedef enum {
    WINDOW,
    FULLSCREEN
} Display_Mode;

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    const char* title;
    Vector2D resolution;
    Display_Mode mode;
} Display;

/**
 * Initializes the Spark engine system.
 *
 * Call this method, before calling anything else!
 */
void spark_init();

void spark_open_window(Display* display);

void spark_sleep(double seconds);



void spark_shutdown();

#endif /* end of include guard: __SPARK_H__ */
