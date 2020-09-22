cmake_minimum_required(VERSION 3.17)
project(raycasting_lodev C)

set(CMAKE_C_STANDARD 11)

add_executable(raycasting_lodev
        mlx/mlx.h
        mlx/mlx_int.h
        mlx/mlx_new_window.h
        mlx/mlx_opengl.h
        mlx/mlx_png.h
        main.c main.h)

target_link_libraries(raycasting_lodev "-framework OpenGL -framework AppKit")
