cmake_minimum_required(VERSION 3.17)
project(raycasting_lodev C)

set(CMAKE_C_STANDARD 11)

LINK_DIRECTORIES(mlx)
LINK_LIBRARIES(mlx)

add_executable(raycasting_lodev
        main.c main.h)

target_link_libraries(raycasting_lodev "-framework OpenGL -framework AppKit")
