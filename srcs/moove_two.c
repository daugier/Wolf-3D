/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:34:03 by daugier           #+#    #+#             */
/*   Updated: 2016/10/25 22:35:20 by daugier          ###   ########.fr       */
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
