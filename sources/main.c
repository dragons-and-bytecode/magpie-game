#include "spark.h"

int main(int argc, char const *argv[]) {
    Display display = {
        .title = "Magpie",
        .resolution = {
            .x = 1280,
            .y = 786
        },
        .mode = WINDOW
    };

    spark_open_window(&display);

    spark_sleep(5.0);

    spark_shutdown();
    return 0;
}
