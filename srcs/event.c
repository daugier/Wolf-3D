/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 00:05:24 by daugier           #+#    #+#             */
/*   Updated: 2016/11/11 22:52:53 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		key_func_bis_two(int keycode, t_struct *data)
{
	if (keycode == 257 || keycode == 258)
	{
		SPEED = 0.1;
		ROT_SPEED = 0.12;
		FAST = 0;
	}
	if (keycode == 49 && (int)POS_X == 12 && (int)POS_Y == 31)
	{
		POS_X = 3.5;
		POS_Y = 31.5;
	}
	if (keycode == 36)
	{
		TIME = 1;
		time(&TIMES);
		AGAIN = 0;
	}
	return (1);
}

static int		key_func_two(int keycode, t_struct *data)
{
	if (keycode == 257 || keycode == 258)
	{
		FAST++;
		SPEED = 0.2;
		ROT_SPEED = 0.15;
	}
	if (keycode == 36)
	{
		AGAIN = 1;
		START = 1;
		POS_X = 14;
		POS_Y = 16;
	}
	if (keycode == 18)
		UN == 1 ? UN-- : UN++;
	return (1);
}

int				key_func(int keycode, t_struct *data)
{
	key_func_two(keycode, data);
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
	return (1);
}

int				key_func_bis(int keycode, t_struct *data)
{
	key_func_bis_two(keycode, data);
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
	return (1);
}
