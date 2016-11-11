/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 22:23:21 by daugier           #+#    #+#             */
/*   Updated: 2016/11/06 16:45:47 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		calc_floor(t_struct *data, int y)
{
	I = (int)MAP[(int)CU_FLOOR_X][(int)CU_FLOOR_Y] - 48;
	CU_DIST = HEIGHT / (2.0 * y - HEIGHT);
	WEIGHT = (CU_DIST - DIST_PLAY) / (DIST_WALL - DIST_PLAY);
	CU_FLOOR_X = WEIGHT * FLOOR_X + (1.0 - WEIGHT) * POS_X;
	CU_FLOOR_Y = WEIGHT * FLOOR_Y + (1.0 - WEIGHT) * POS_Y;
	FLOOR_TEXX = (int)(CU_FLOOR_X * TEXT_WIDTH[I]) % TEXT_WIDTH[I];
	FLOOR_TEXY = (int)(CU_FLOOR_Y * TEXT_HEIGHT[I]) % TEXT_HEIGHT[I];
}

static void		calc_vect_floor(t_struct *data)
{
	if (SIDE == 0 && RAYDIR_X > 0)
	{
		FLOOR_X = MAP_X;
		FLOOR_Y = MAP_Y + WALLX;
	}
	else if (SIDE == 0 && RAYDIR_X < 0)
	{
		FLOOR_X = MAP_X + 1.0;
		FLOOR_Y = MAP_Y + WALLX;
	}
	else if (SIDE == 1 && RAYDIR_Y > 0)
	{
		FLOOR_X = MAP_X + WALLX;
		FLOOR_Y = MAP_Y;
	}
	else
	{
		FLOOR_X = MAP_X + WALLX;
		FLOOR_Y = MAP_Y + 1.0;
	}
}

static void		draw_sky(t_struct *data, int x, int y, int pixel)
{
	if (I == 0)
		I = 8;
	FLOOR_TEXX = (int)(CU_FLOOR_X * TEXT_WIDTH[I]) % TEXT_WIDTH[I];
	FLOOR_TEXY = (int)(CU_FLOOR_Y * TEXT_HEIGHT[I]) % TEXT_HEIGHT[I];
	pixel = FLOOR_TEXY * TEXT_SIZE_LINE[I] + FLOOR_TEXX * (TEXT_BPP[I] / 8);
	get_texture(data, pixel);
	if (UN && MAP[(int)CU_FLOOR_X][(int)CU_FLOOR_Y] != '1')
	{
		if (TIME % 2 == 0)
			COLOR &= 0x000000;
	}
	if (TIME <= 10 && TIME % 2 == 0)
		COLOR &= RED;
	write_data_pixel(data, x, HEIGHT - y, COLOR);
}

void			draw_floor(t_struct *data, int x, int y)
{
	int	pixel;

	calc_vect_floor(data);
	DIST_WALL = PERPWALLDIST;
	DIST_PLAY = 0;
	if (DRAWEND < 0)
		DRAWEND = HEIGHT - 1;
	y = DRAWEND;
	while (++y < HEIGHT)
	{
		calc_floor(data, y);
		pixel = FLOOR_TEXY * TEXT_SIZE_LINE[I] + FLOOR_TEXX * (TEXT_BPP[I] / 8);
		get_texture(data, pixel);
		COLOR = (COLOR >> 1) & 8355711;
		if (UN && MAP[(int)CU_FLOOR_X][(int)CU_FLOOR_Y] != '1')
		{
			COLOR &= 0xFF0000;
			if (TIME % 2 == 0)
				COLOR &= 0x000000;
		}
		if (TIME <= 10 && TIME % 2 == 0)
			COLOR &= RED;
		write_data_pixel(data, x, y, COLOR);
		draw_sky(data, x, y, pixel);
	}
}
