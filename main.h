#ifndef RAYCASTING_LODEV_MAIN_H
# define RAYCASTING_LODEV_MAIN_H

# include <math.h>
# include <stdlib.h> // exit(0)
# include "mlx/mlx.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define mapWidth 24
# define mapHeight 24
# define width 640
# define height 480

# define K_A 0
# define K_D 2
# define K_S 1
# define K_W 13
# define K_AR_L 123
# define K_AR_R 124
# define K_ESC 53

typedef struct	s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

#endif //RAYCASTING_LODEV_MAIN_H
