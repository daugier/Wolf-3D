/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 22:23:21 by daugier           #+#    #+#             */
/*   Updated: 2016/10/21 23:31:15 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		calc_vect_floor(t_struct *data)
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

void		get_texture_floor(t_struct *data, int pixel)
{
	if (I == 1)
		COLOR = WALL_DATA[7][pixel] + WALL_DATA[7][pixel + 1] * 256 + WALL_DATA[7][pixel + 2] * 65536;
	else
		COLOR = WALL_DATA[6][pixel] + WALL_DATA[6][pixel + 1] * 256 + WALL_DATA[6][pixel + 2] * 65536;
}

void		draw_sky(t_struct *data, int x, int y, int pixel)
{
	I = 1;
	FLOOR_TEXX = (int)(CU_FLOOR_X * TEXT_WIDTH[7]) % TEXT_WIDTH[7];
	FLOOR_TEXY = (int)(CU_FLOOR_Y * TEXT_HEIGHT[7]) % TEXT_HEIGHT[7];
	write_data_pixel(data, x, y, COLOR);
	pixel = (FLOOR_TEXY * TEXT_SIZE_LINE[7] + FLOOR_TEXX) * (TEXT_BPP[7] / 8);
	get_texture_floor(data, pixel);
	COLOR = (TEXT_WIDTH[7] * FLOOR_TEXY + FLOOR_TEXX);
	write_data_pixel(data, x, y, COLOR);
}

void		draw_sky_floor(t_struct *data, int x, int y)
{
	int	pixel;

	DIST_WALL = PERPWALLDIST;
	DIST_PLAY = 0.0;
	if (DRAWEND < 0)
		DRAWEND = HEIGHT;
	y = DRAWEND - 1;
	while (++y < HEIGHT)
	{
		I = 0;
		calc_vect_floor(data);
		CU_DIST = HEIGHT / (2.0 * y - HEIGHT);
		WEIGHT = (CU_DIST - DIST_PLAY) / (DIST_WALL - DIST_PLAY);
		CU_FLOOR_X = WEIGHT * FLOOR_X + (1.0 - WEIGHT) * POS_X;
		CU_FLOOR_Y = WEIGHT * FLOOR_Y + (1.0 - WEIGHT) * POS_Y;
		FLOOR_TEXX = (int)(CU_FLOOR_X * TEXT_WIDTH[6]) % TEXT_WIDTH[6];
		FLOOR_TEXY = (int)(CU_FLOOR_Y * TEXT_HEIGHT[6]) % TEXT_HEIGHT[6];
		pixel = (FLOOR_TEXY * TEXT_SIZE_LINE[6] + FLOOR_TEXX) * (TEXT_BPP[6] / 8);
		get_texture_floor(data, pixel);
		COLOR = (TEXT_WIDTH[6] * FLOOR_TEXY + FLOOR_TEXX) >> 1 & 8355711;
		write_data_pixel(data, x, y, COLOR);
		draw_sky(data, x, HEIGHT - y, pixel);
	}
}
