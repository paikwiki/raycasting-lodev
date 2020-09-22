#ifndef RAYCASTING_LODEV_MAIN_H
# define RAYCASTING_LODEV_MAIN_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define mapWidth 24
# define mapHeight 24
# define width 640
# define height 480

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
