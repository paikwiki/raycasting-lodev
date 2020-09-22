#include "main.h"

int worldMap[mapWidth][mapHeight] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// draw the pixels of the stripe as a vertical line 수직 라인을 그리는데 쓸 수 있는 유용한 함수!
void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

void	calc(t_info *info)
{
	int	x;
	int	color;

	x = 0;
	color = 0;
	while (x < width) // for(int x = 0; x < w; x++) {}
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)width - 1; // x-coordinate in camera space (-1 ~ 1까지)
		double rayDirX = info->dirX + info->planeX * cameraX; // cameraX 값이 변하면서 광선벡터를 촤라락 변경해 줌
		double rayDirY = info->dirY + info->planeY * cameraX;

		//which box of the map we're in
		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		double sideDistX; // 플레이어의 현위치에서 벡터 방향에 있는, 최초의 수"직"축 그리드(y)에 닿는 빗변의 길이(벡터값)
		double sideDistY; // 플레이어의 현위치에서 벡터 방향에 있는, 최초의 수"평"축 그리드(x에 닿는 빗변의 길이(벡터값)

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX); // sideDistX에서 다음 수직축 그리드(y)에 닿았을 때 빗변의 길이(벡터값)
		double deltaDistY = fabs(1 / rayDirY); // sideDistY에서 다음 수평축 그리드(x)에 닿았을 때 빗변의 길이(벡터값)
		double perpWallDist; // 수직거리. 어안렌즈 효과를 보정하기 위한 간단한 방법

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0) // 광선이 향하는 방향에 따라 증가/감소를 결정 "만약 광선의 x방향 rayDirX 의 값이 양수라면 stepX 의 값은 +1 로, 음수라면 -1 로 설정합니다."
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}


		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}

		// "어안렌즈 효과 (fisheye effect) 는 실제 거리 값을 사용했을 때 모든 벽이 둥글게 보여서 회전할 때 울렁거릴 수도 있는 현상을 말합니다.
		//  이러한 어안렌즈 효과 를 피하기 위해, 플레이어 위치까지의 유클리드 거리 대신에, 카메라 평면까지의 거리 (또는 카메라 쪽으로 플레이어에 투사된 지점의 거리)를 사용할 것입니다."
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + height / 2;
		if(drawStart < 0)
			drawStart = 0; // 0보다 작으면 화면에 안 나오니까 0으로 보정
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1; // height보다 커도 화면에 안 나오니까 height - 1로 보정. -1을 하는 건 일단 그냥 받아들이기로..

//		// 좌표상의 값에 따라 벽 색깔 처리는 과제 밖의 영역이므로 과감히 단색 처리
//		if (worldMap[mapX][mapY] == 1)
//			color = 0xFF0000;
//		else if (worldMap[mapX][mapY] == 2)
//			color = 0x00FF00;
//		else if (worldMap[mapX][mapY] == 3)
//			color = 0x0000FF;
//		else if (worldMap[mapX][mapY] == 4)
//			color = 0xFFFFFF;
//		else
//			color = 0xFFFF00;

		color = 0x0000FF;
		if (side == 1)
			color = color / 2;

		verLine(info, x, drawStart, drawEnd, color);
		x++;
	}
}

int	key_press(int key, t_info *info)
{
	//move forward if no wall in front of you
	if (key == K_W)
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	//move right if no wall in your right side
	if (key == K_D)
	{
		if (!worldMap[(int)(info->posX + info->planeX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->planeX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->planeY * info->moveSpeed)])
			info->posY += info->planeY * info->moveSpeed;
	}
	//move left if no wall in your left side
	if (key == K_A)
	{
		if (!worldMap[(int)(info->posX - info->planeX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->planeX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->planeY * info->moveSpeed)])
			info->posY -= info->planeY * info->moveSpeed;
	}
	//rotate to the right
	if (key == K_AR_R)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == K_AR_L)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void clear_screen(t_info *info)
{
	int i, j;
	i = -1;
	while(++i < width)
	{
		verLine(info, i, 0, height, 0x111111);
	}
}

int	main_loop(t_info *info)
{
	clear_screen(info); // 화면을 다시 계산해서 그리기 전에 한번 지워줌
	calc(info);
	return (0);
}

int main(void)
{
	t_info info;
	info.mlx = mlx_init();

	info.posX = 12; info.posY = 5; //x and y start position
	info.dirX = -1; info.dirY = 0; //initial direction vector
	info.planeX = 0; info.planeY = 0.66; //the 2d raycaster version of camera plane

	info.moveSpeed = 0.02;
	info.rotSpeed = 0.02;

	info.win = mlx_new_window(info.mlx, width, height, "Raycaster");

	mlx_loop_hook(info.mlx, &main_loop, &info); // while(!done()) {}
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx);

	return (0);
}
