/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2016/10/25 18:20:38 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				quit_func(t_struct *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
	return (1);
}

void			free_all(t_struct *data)
{
	free(data);
	data = NULL;
}

int				main(int ac, char **av)
{
	t_struct		*data;

	if (ac != 2)
	{
		ft_putstr("Usage : ./wolf3d <Wolf Map Name>\n");
		exit(EXIT_FAILURE);
	}
	data = ft_init_struct(av[1]);
	wolf(data);
	mlx_loop_hook(MLX, wolf, data);
	mlx_hook(WIN, 17, ButtonMotionMask, quit_func, data);
	mlx_hook(WIN, KeyPress, KeyPressMask, key_func, data);
	mlx_hook(WIN, KeyRelease, KeyReleaseMask, key_func_bis, data);
	mlx_hook(WIN, ButtonPress, ButtonPressMask, mouse_func, data);
	mlx_loop(MLX);
	free_all(data);
	return (0);
}
