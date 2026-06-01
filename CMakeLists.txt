cmake_minimum_required(VERSION 3.29)
project(mini_rasterizer C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

include(FetchContent)

FetchContent_Declare(
        minifb
        GIT_REPOSITORY https://github.com/emoon/minifb.git
        GIT_TAG        v0.10.1
)

FetchContent_MakeAvailable(minifb)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE minifb)