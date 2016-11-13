
static int running = 0;

void start_application()
{
    if (running == 1)
    {
        printf("Error! Application already running!\n");
        return;
    }

    running = 1;
}

void stop_application()
{
    if (running != 1)
    {
        printf("Error! Application stop called without running application.\n");
        return;
    }

    running = 0;
}

