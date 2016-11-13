#include <stdio.h>
#include "buildinfo.h"

int main(int argc, char *argv[])
{
    printf("Version: %s Build on: %s\n", GIT_DESCRIBE_VERSION, BUILD_DATE);
    printf("Hello world!\n");
    return 0;
}

