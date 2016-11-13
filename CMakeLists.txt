cmake_minimum_required(VERSION 3.1.0)

project(GitWorkshop)

set(GIT_WORKSHOP_SOURCE
    main.c
    hello_world.c
)

set(GIT_WORKSHOP_HEADERS
    hello_world.h
)

add_executable(hello_world ${GIT_WORKSHOP_SOURCE} ${GIT_WORKSHOP_HEADERS})

