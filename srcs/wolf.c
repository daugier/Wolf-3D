/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:50:49 by daugier           #+#    #+#             */
/*   Updated: 2016/10/25 19:59:56 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	display_touch(t_struct *data)
{
	int	color;

	color = 0xFF0000;
	mlx_string_put(MLX, WIN, 500, 250, 0xFF6600, "HOW TO PLAY");
	mlx_string_put(MLX, WIN, 400, 300, 0x000000, "Press 1 for Dark mode after start!");
	mlx_string_put(MLX, WIN, 450, 350, color, "Left Straff  ->  A");
	mlx_string_put(MLX, WIN, 450, 370, color, "Right Straff ->  D");
	mlx_string_put(MLX, WIN, 450, 390, color, "Walk         ->  ^");
	mlx_string_put(MLX, WIN, 450, 410, color, "Back         ->  v");
	mlx_string_put(MLX, WIN, 450, 430, color, "Left Rotate  ->  < ");
	mlx_string_put(MLX, WIN, 450, 450, color, "Right Rotate ->  >");
	mlx_string_put(MLX, WIN, 450, 470, color, "Speed        ->  Shift");
}

void	display_start(t_struct *data)
{
	int	x;
	int	y;
	int	color;

	while (++x < WIDTH && (y = -1))
		while (++y < HEIGHT)
		{
			color = 0xFFD800;
			write_data_pixel(data, x, y, color);
		}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	color = 0xA633;
	time(&TIMES);
	if (TIMES % 2 == 0)
		mlx_string_put(MLX, WIN, 450, 150, color, "Press ENTER for START ");
	mlx_string_put(MLX, WIN, 350, 100, color, "Try to finish the labitynth before 60 Seconds !");
	display_touch(data);
}

void	ft_moove(t_struct *data)
{
	if (MOOVE & WALK)
		ft_walk(data);
	if (MOOVE & BACK)
		ft_back(data);
	if (MOOVE & LEFT)
		ft_left(data);
	if (MOOVE & RIGHT)
		ft_right(data);
	if (MOOVE & TURN_LEFT)
		ft_rotate_left(data);
	if (MOOVE & TURN_RIGHT)
		ft_rotate_right(data);
}

void	write_data_pixel(t_struct *data, int x, int y, int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	b = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		DATA[y * SIZE_LINE + x * (BPP / 8)] = r;
		DATA[y * SIZE_LINE + x * (BPP / 8) + 1] = g;
		DATA[y * SIZE_LINE + x * (BPP / 8) + 2] = b;
		if (FAST)
			DATA[y * SIZE_LINE + x * (BPP / 8) + 3] = 50;
	}
}

int		wolf(t_struct *data)
{

	ft_new_screen(data);
	if (!START)
		display_start(data);
	else if (TIME == 0)
		display_end(data, 10);
	else if (MAP[(int)POS_X][(int)POS_Y] == '1' && TIME > 0)
		display_end(data, 11);
	else if (TIME && START)
	{
		X = -1;
		while (++X <= WIDTH)
		{
			ray_cast_wall(data, X);
		}
		ft_moove(data);
		mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
		info(data);
	}
	return (0);
}
