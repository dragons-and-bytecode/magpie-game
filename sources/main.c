#include "spark.h"

int main(int argc, char const *argv[]) {
    Display display = {
        .title = "Magpie",
        .resolution = {
            .x = 1920,
            .y = 1080
        },
        .mode = WINDOW
    };

    spark_open_window(&display);
    
    spark_sleep(5.0);

    spark_shutdown();
    return 0;
}
