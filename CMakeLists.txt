cmake_minimum_required(VERSION 3.1.0)

project(GitWorkshop)

function(get_git_describe_tag git_describe_tag)
    if (NOT GIT_FOUND)
        find_package(Git REQUIRED)
    endif()

    execute_process(
        COMMAND ${GIT_EXECUTABLE} "describe" "--tags" "--long"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_DESCRIBE_OUTPUT
        ERROR_VARIABLE GIT_DESCRIBE_ERROR_OUTPUT
        RESULT_VARIABLE GIT_DESCRIBE_RESULT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    if (NOT GIT_DESCRIBE_RESULT EQUAL 0)
        message(FATAL_ERROR "Could not parse git describe version.\nOutput was ${GIT_DESCRIBE_ERROR_OUTPUT}")
    endif()

    set(${git_describe_tag} ${GIT_DESCRIBE_OUTPUT} PARENT_SCOPE)
endfunction()

function(generate_build_info_header)
    get_git_describe_tag(git_describe_tag)

    set(GITWORKSHOP_GIT_DESCRIBE ${git_describe_tag})
    string(TIMESTAMP GITWORKSHOP_BUILD_DATE "%Y-%m-%d")

    configure_file(
        ${CMAKE_SOURCE_DIR}/buildinfo.h.in
        ${CMAKE_BINARY_DIR}/buildinfo.h
        @ONLY
    )
endfunction()

set(GIT_WORKSHOP_SOURCE
    main.c
)

add_executable(hello_world ${GIT_WORKSHOP_SOURCE})

generate_build_info_header()

target_include_directories(hello_world
    PRIVATE ${CMAKE_BINARY_DIR}
)
