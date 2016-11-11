/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:34:03 by daugier           #+#    #+#             */
/*   Updated: 2016/11/11 20:44:13 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_back(t_struct *data)
{
	double		x;
	double		y;

	x = (DIRX < 0 ? -0.15 : 0.15);
	y = (DIRY < 0 ? -0.15 : 0.15);
	if (MAP[(int)(POS_X - DIRX * SPEED - x)][(int)POS_Y] < '2' ||
			(MAP[(int)(POS_X - DIRX * SPEED - x)][(int)POS_Y] > '5'))
		POS_X -= DIRX * SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y - DIRY * SPEED - y)] < '2' ||
			(MAP[(int)(POS_X)][(int)(POS_Y - DIRY * SPEED - y)] > '5'))
		POS_Y -= DIRY * SPEED;
}
