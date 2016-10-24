/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:50:49 by daugier           #+#    #+#             */
/*   Updated: 2016/10/25 00:14:51 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
			DATA[y * SIZE_LINE + x * (BPP / 8) + 3] = 150;
	}
}

int		wolf(t_struct *data)
{

	ft_new_screen(data);
	if (TIME == 0)
		display_end(data, 10);
	if (MAP[(int)POS_X][(int)POS_Y] == '1' && TIME > 0)
		display_end(data, 11);
	else if (TIME)
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
