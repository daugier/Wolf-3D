/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:23:14 by daugier           #+#    #+#             */
/*   Updated: 2016/10/24 20:53:59 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_back(t_struct *data)
{
	if (MAP[(int)(POS_X - DIRX * SPEED)][(int)POS_Y] < '2')
		POS_X -= DIRX * SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y - DIRY * SPEED)] < '2')
		POS_Y -= DIRY * SPEED;
}

void		ft_walk(t_struct *data)
{
	if (MAP[(int)(POS_X + DIRX * SPEED)][(int)POS_Y] < '2')
		POS_X += DIRX * SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y + DIRY * SPEED)] < '2')
		POS_Y += DIRY * SPEED;
}

void		ft_right(t_struct *data)
{
	if (MAP[(int)(POS_X + PLANEX * SPEED)][(int)POS_Y] < '2')
		POS_X += PLANEX * SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y + PLANEY * SPEED)] < '2')
		POS_Y += PLANEY * SPEED;
}

void		ft_left(t_struct *data)
{
	if (MAP[(int)(POS_X - PLANEX * SPEED)][(int)POS_Y] < '2')
		POS_X -= PLANEX * SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y - PLANEY * SPEED)] < '2')
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
