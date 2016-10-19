/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:21:29 by daugier           #+#    #+#             */
/*   Updated: 2016/10/06 17:16:03 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		calc_vect(t_struct *data)
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

void		touch_wall(t_struct *data)
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
		if (MAP[MAP_X][MAP_Y] != '0')
			HIT = 1;
	}
}

void		draw(t_struct *data, int x)
{
	int	y;
	
	y = DRAWSTART - 1;
	while (++y < DRAWEND)
	{
		COLOR = MAROON;
		if (SIDE == 1)
			COLOR = GREEN;
		write_data_pixel(data, x, y, COLOR);
	}
}

void		draw_sky_floor(t_struct *data, int x, int y)
{
	if (DRAWEND < 0)
		DRAWEND = HEIGHT;
	y = DRAWEND - 1;
	while (++y < HEIGHT)
	{
		write_data_pixel(data, x, y, ORANGE);
		write_data_pixel(data, x, HEIGHT - y - 1, GRAY);
		if (JUMP == 1)
			write_data_pixel(data, x, HEIGHT - y - 1 + 95, GRAY);
	}
}

void		ray_cast_wall(t_struct *data, int x)
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
	calc_vect(data);
	touch_wall(data);
	if (SIDE == 0)
		PERPWALLDIST = (MAP_X - RAYPOS_X + (1 - STEP_X) / 2) / RAYDIR_X;
	else
		PERPWALLDIST = (MAP_Y - RAYPOS_Y + (1 - STEP_Y) / 2) / RAYDIR_Y;
	H_LINE = HEIGHT / PERPWALLDIST;
	DRAWSTART = (-H_LINE / 2 + HEIGHT / 2);
	DRAWEND = (H_LINE / 2 + HEIGHT / 2);
	if (DRAWSTART < 0)
		DRAWSTART = 0;
	if (DRAWEND >= HEIGHT)
		DRAWEND = HEIGHT - 1;
	if (JUMP == 1)
	{
		DRAWEND *= 1.12;
		DRAWSTART *= 1.12;
	}
	draw(data, x);
	draw_sky_floor(data, x, Y);
}
