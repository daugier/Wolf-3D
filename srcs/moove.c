/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:23:14 by daugier           #+#    #+#             */
/*   Updated: 2016/12/03 16:06:16 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void		ft_walk(t_struct *data)
{
	double		x;
	double		y;

	x = (DIRX < 0 ? -0.15 : 0.15);
	y = (DIRY < 0 ? -0.15 : 0.15);
	if (MAP[(int)(POS_X + DIRX * SPEED + x)][(int)(POS_Y)] < '5' &&
			MAP[(int)(POS_X + (DIRX + x) * SPEED)][(int)(POS_Y)] < '5' &&
			MAP[(int)(POS_X + DIRX * SPEED)][(int)(POS_Y + y)] &&
			MAP[(int)(POS_X + DIRX * SPEED + x)][(int)(POS_Y + y)] < '5')
		POS_X += DIRX * SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y + DIRY * SPEED + y)] < '5' &&
			MAP[(int)(POS_X)][(int)(POS_Y + (DIRY + y) * SPEED)] < '5' &&
			MAP[(int)(POS_X + x)][(int)(POS_Y + DIRY * SPEED)] &&
			MAP[(int)(POS_X + x)][(int)(POS_Y + DIRY * SPEED + y)] < '5')
		POS_Y += DIRY * SPEED;
}

void		ft_right(t_struct *data)
{
	double		x;
	double		y;

	x = (PLANEX < 0 ? -0.15 : 0.15);
	y = (PLANEY < 0 ? -0.15 : 0.15);
	if (MAP[(int)(POS_X + PLANEX * SPEED + x)][(int)(POS_Y)] < '5' &&
			MAP[(int)(POS_X + (PLANEX + x) * SPEED)][(int)(POS_Y)] < '5' &&
			MAP[(int)(POS_X + PLANEX * SPEED)][(int)(POS_Y + y)] < '5' &&
		MAP[(int)(POS_X + PLANEX * SPEED + x)][(int)(POS_Y + y)] < '5')
		POS_X += PLANEX * SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y + PLANEY * SPEED + y)] < '5' &&
			MAP[(int)(POS_X)][(int)(POS_Y + (PLANEY + y) * SPEED)] < '5' &&
			MAP[(int)(POS_X + x)][(int)(POS_Y + PLANEY * SPEED)] < '5' &&
			MAP[(int)(POS_X + x)][(int)(POS_Y + PLANEY * SPEED + y)] < '5')
		POS_Y += PLANEY * SPEED;
}

void		ft_left(t_struct *data)
{
	double		x;
	double		y;

	x = (PLANEX < 0 ? -0.15 : 0.15);
	y = (PLANEY < 0 ? -0.15 : 0.15);
	if (MAP[(int)(POS_X - PLANEX * SPEED - x)][(int)(POS_Y)] < '5' &&
			MAP[(int)(POS_X - (PLANEX + x) * SPEED)][(int)(POS_Y)] < '5' &&
			MAP[(int)(POS_X - PLANEX * SPEED)][(int)(POS_Y - y)] &&
			MAP[(int)(POS_X - PLANEX * SPEED - x)][(int)(POS_Y - y)] < '5')
		POS_X -= PLANEX * SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y - PLANEY * SPEED - y)] < '5' &&
			MAP[(int)(POS_X)][(int)(POS_Y - (PLANEY - y) * SPEED)] < '5' &&
			MAP[(int)(POS_X - x)][(int)(POS_Y - PLANEY * SPEED)] &&
			MAP[(int)(POS_X - x)][(int)(POS_Y - PLANEY * SPEED - y)] < '5')
		POS_Y -= PLANEY * SPEED;
}

void		ft_rotate_right(t_struct *data)
{
	double olddirx;
	double oldplanex;

	olddirx = DIRX;
	DIRX = DIRX * cos(-ROT_SPEED) - DIRY * sin(-ROT_SPEED);
	DIRY = olddirx * sin(-ROT_SPEED) + DIRY * cos(-ROT_SPEED);
	oldplanex = PLANEX;
	PLANEX = PLANEX * cos(-ROT_SPEED) - PLANEY * sin(-ROT_SPEED);
	PLANEY = oldplanex * sin(-ROT_SPEED) + PLANEY * cos(-ROT_SPEED);
}

void		ft_rotate_left(t_struct *data)
{
	double olddirx;
	double oldplanex;

	olddirx = DIRX;
	DIRX = DIRX * cos(ROT_SPEED) - DIRY * sin(ROT_SPEED);
	DIRY = olddirx * sin(ROT_SPEED) + DIRY * cos(ROT_SPEED);
	oldplanex = PLANEX;
	PLANEX = PLANEX * cos(ROT_SPEED) - PLANEY * sin(ROT_SPEED);
	PLANEY = oldplanex * sin(ROT_SPEED) + PLANEY * cos(ROT_SPEED);
}
