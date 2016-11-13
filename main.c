#include <stdio.h>
#include "application.h"
#include "crash_handler.h"
#include "text_manager.h"

const int ERROR_CODE = 1337;

int main(int argc, char *argv[])
{
    crash_result result = 0;

    start_application();

    printf("Hello world!\n");

    result = handle_crash(ERROR_CODE);

    print_something("Closing application.");

    stop_application();
    return 0;
}

