/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:34:03 by daugier           #+#    #+#             */
/*   Updated: 2016/11/22 20:54:07 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_back(t_struct *data)
{
	double		x;
	double		y;

	x = (DIRX < 0 ? -0.15 : 0.15);
	y = (DIRY < 0 ? -0.15 : 0.15);
	if (MAP[(int)(POS_X - DIRX * SPEED - x)][(int)(POS_Y - y)] < '5')
		POS_X -= DIRX * SPEED;
	if (MAP[(int)(POS_X - x)][(int)(POS_Y - DIRY * SPEED - y)] < '5')
		POS_Y -= DIRY * SPEED;
}

void		ft_teleportation(t_struct *data)
{
	if (MAP[(int)(POS_X)][(int)(POS_Y)] == '4' &&
			(MAP[3][31] == '1' || MAP[3][31] == '0'))
	{
		POS_X = 3.5;
		POS_Y = 31;
	}
}
