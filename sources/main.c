#include "spark.h"

void run_example_scene() {
    /*
     * 1. Init scene
     */

    /*
     * 2. create stuff
     */


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

    spark_sleep(5.0);

    spark_shutdown();
    return 0;
}
