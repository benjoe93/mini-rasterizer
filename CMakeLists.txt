cmake_minimum_required(VERSION 3.29)
project(mini_rasterizer C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include(FetchContent)

FetchContent_Declare(
        minifb
        GIT_REPOSITORY https://github.com/emoon/minifb.git
        GIT_TAG        v0.10.1
)

FetchContent_MakeAvailable(minifb)

set(SOURCES
    "src/main.c"
    "src/file_utils.c"
    "src/math_utils.c"
    "src/renderer.c"
)

set(HEADERS
    "include/file_utils.h"
    "include/math_utils.h"
    "include/renderer.h"
    "include/types.h"
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Make "saved" folder and pass into the project
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/saved)
target_compile_definitions(${PROJECT_NAME} PRIVATE OUTPUT_DIR="${CMAKE_SOURCE_DIR}/saved")

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
    target_compile_options(${PROJECT_NAME} PRIVATE "/W4" "/WX")
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Werror")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE minifb)