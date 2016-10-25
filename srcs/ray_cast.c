/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:21:29 by daugier           #+#    #+#             */
/*   Updated: 2016/10/25 23:15:41 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		calc_wall(t_struct *data, int y)
{
	int d;

	I = (int)(MAP[MAP_X][MAP_Y]) - 48;
	if (SIDE == 0)
		WALLX = RAYPOS_Y + PERPWALLDIST * RAYDIR_Y;
	else
		WALLX = RAYPOS_X + PERPWALLDIST * RAYDIR_X;
	WALLX -= floor((WALLX));
	TEXX = (int)(WALLX * (double)(TEXT_WIDTH[I]));
	if (SIDE == 0 && RAYDIR_X > 0)
		TEXX = TEXT_WIDTH[I] - TEXX - 1;
	if (SIDE == 1 && RAYDIR_Y < 0)
		TEXX = TEXT_WIDTH[I] - TEXX - 1;
	d = y * 256 - HEIGHT * 128 + (H_LINE * 128);
	TEXY = ((d * TEXT_HEIGHT[I]) / H_LINE) / 256;
}

static void		calc_vect_wall(t_struct *data)
{
	if (RAYDIR_X < 0)
	{
		STEP_X = -1;
		SIDEDIST_X = (RAYPOS_X - MAP_X) * DELTADIST_X;
	}
	else
	{
		STEP_X = 1;
		SIDEDIST_X = (MAP_X + 1.0 - RAYPOS_X) * DELTADIST_X;
	}
	if (RAYDIR_Y < 0)
	{
		STEP_Y = -1;
		SIDEDIST_Y = (RAYPOS_Y - MAP_Y) * DELTADIST_Y;
	}
	else
	{
		STEP_Y = 1;
		SIDEDIST_Y = (MAP_Y + 1.0 - RAYPOS_Y) * DELTADIST_Y;
	}
}

static void		touch_wall(t_struct *data)
{
	HIT = 0;
	while (HIT == 0)
	{
		if (SIDEDIST_X < SIDEDIST_Y)
		{
			SIDEDIST_X += DELTADIST_X;
			MAP_X += STEP_X;
			SIDE = 0;
		}
		else
		{
			SIDEDIST_Y += DELTADIST_Y;
			MAP_Y += STEP_Y;
			SIDE = 1;
		}
		if (MAP[MAP_X][MAP_Y] > '1')
			HIT = 1;
	}
}

static void		draw_wall(t_struct *data, int x)
{
	int	y;
	int	pixel;

	y = DRAWSTART - 1;
	while (++y < DRAWEND)
	{
		calc_wall(data, y);
		pixel = TEXY * TEXT_SIZE_LINE[I] + TEXX * (TEXT_BPP[I] / 8);
		get_texture(data, pixel);
		if (SIDE == 1)
			COLOR = (COLOR >> 1) & 8355711;
		if (UN)
		{
			COLOR &= 0xFF0000;
			if (TIME % 2 == 0)
				COLOR &= 0x000000;
		}
		if (TIME <= 10 && TIME % 2 == 0)
			COLOR &= RED;
		write_data_pixel(data, x, y, COLOR);
	}
}

void			ray_cast_wall(t_struct *data, int x)
{
	CAM_X = (2 * x / (double)WIDTH) - 1;
	RAYPOS_X = POS_X;
	RAYPOS_Y = POS_Y;
	RAYDIR_X = DIRX + PLANEX * CAM_X;
	RAYDIR_Y = DIRY + PLANEY * CAM_X;
	MAP_X = RAYPOS_X;
	MAP_Y = RAYPOS_Y;
	DELTADIST_X = sqrt(1 + (RAYDIR_Y * RAYDIR_Y) / (RAYDIR_X * RAYDIR_X));
	DELTADIST_Y = sqrt(1 + (RAYDIR_X * RAYDIR_X) / (RAYDIR_Y * RAYDIR_Y));
	calc_vect_wall(data);
	touch_wall(data);
	PERPWALLDIST = (MAP_Y - RAYPOS_Y + (1 - STEP_Y) / 2) / RAYDIR_Y;
	if (SIDE == 0)
		PERPWALLDIST = (MAP_X - RAYPOS_X + (1 - STEP_X) / 2) / RAYDIR_X;
	H_LINE = HEIGHT / PERPWALLDIST;
	DRAWSTART = (-H_LINE / 2 + HEIGHT / 2);
	DRAWEND = (H_LINE / 2 + HEIGHT / 2);
	DRAWSTART < 0 ? DRAWSTART = 0 : 0;
	DRAWEND >= HEIGHT ? DRAWEND = HEIGHT - 1 : 0;
	draw_wall(data, x);
	draw_floor(data, x, Y);
}
