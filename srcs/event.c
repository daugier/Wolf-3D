/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 00:05:24 by daugier           #+#    #+#             */
/*   Updated: 2016/10/20 15:37:47 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			mouse_func(int button, int x, int y, t_struct *data)
{
	if (y < -2 && y > -21 && x > 5 && x < 23)
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int			key_func(int keycode, t_struct *data)
{
	ft_new_screen(data);
	if (keycode == 53)
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 126 || keycode == 13)
		MOOVE |= WALK;
	if (keycode == 125 || keycode == 1)
		MOOVE |= BACK;
	if (keycode == 123)
		MOOVE |= TURN_LEFT;
	if (keycode == 124)
		MOOVE |= TURN_RIGHT;
	if (keycode == 0)
		MOOVE |= LEFT;
	if (keycode == 2)
		MOOVE |= RIGHT;
	if (keycode == 257)
	{
		FAST++;
		SPEED = 0.3;
	}
	if (keycode == 49)
		JUMP++;
	if (keycode == 261)
		SIT++;
	return (1);
}

int			key_func_bis(int keycode, t_struct *data)
{
	if (keycode == 126 || keycode == 13)
		MOOVE ^= WALK;
	if (keycode == 125 || keycode == 1)
		MOOVE ^= BACK;
	if (keycode == 123)
		MOOVE ^= TURN_LEFT;
	if (keycode == 124)
		MOOVE ^= TURN_RIGHT;
	if (keycode == 0)
		MOOVE ^= LEFT;
	if (keycode == 2)
		MOOVE ^= RIGHT;
	if (keycode == 257)
	{
		SPEED = 0.1;
		FAST = 0;
	}
	if (keycode == 49)
		JUMP = 0;
	if (keycode == 261)
		SIT = 0;
	return (1);
}
