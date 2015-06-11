#ifndef __SPARK_H__
#define __SPARK_H__

#include "base.h"
#include "context_store.h"

typedef enum {
    WINDOW,
    FULLSCREEN
} Display_Mode;

typedef struct {
    const char* title;
    Vector2D resolution;
    Display_Mode mode;
    context_id context;
} Display;

/**
 * Initializes the Spark engine system.
 *
 * Call this method, before calling anything else!
 */
void spark_init();

/**
 * Opens a window with the properties as defined in the given
 * display attribute.
 *
 * > **Caution:** This function will create a context_id and store it in the
 * > context field of the given display attribute, to handle the context in
 * > following calls. Overwriting this set id and calling any other spark
 * > functions with a display with overwritten context will result in
 * > undefined behaviour
 *
 * @param display [description]
 */
void spark_open_window(Display* display);

void spark_sleep(double seconds);

#include "spark_image.h"

void spark_shutdown();

#endif /* end of include guard: __SPARK_H__ */
