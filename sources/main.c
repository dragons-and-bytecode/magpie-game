#include "spark.h"

void run_example_scene(Display* display) {
    /*
     * 1. Init scene
     */

    /*
     * 2. create stuff
     */

    Image* logo = spark_create_image_from_file_in_display(
        "assets/images/logo.png", display);
    spark_display_immidiately(logo);

    /*
     * 3. display stuff
     */


    /*
     * 4. wait
     */

    /*
     * 5. exit
     */

}

int main(int argc, char const *argv[]) {
    spark_init();

    Display display = {
        .title = "Magpie",
        .resolution = {
            .x = 1280,
            .y = 786
        },
        .mode = WINDOW
    };

    spark_open_window(&display);

    run_example_scene(&display);

    spark_sleep(2.0);

    spark_shutdown();
    return 0;
}
