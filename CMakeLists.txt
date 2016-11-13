cmake_minimum_required(VERSION 3.1.0)

project(GitWorkshop)

set(GIT_WORKSHOP_SOURCE
    main.c
    application.c
    application.h
    crash_handler.c
    crash_handler.h
    text_manager.c
    text_manager.h
)

add_executable(hello_world ${GIT_WORKSHOP_SOURCE})

