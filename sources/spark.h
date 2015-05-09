#ifndef __SPARK_H__
#define __SPARK_H__

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

void spark_init_gfx(Display* display);

void spark_sleep(double seconds);

void spark_shutdown();

#endif /* end of include guard: __SPARK_H__ */
