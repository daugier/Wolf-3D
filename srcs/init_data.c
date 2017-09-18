/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:15:06 by daugier           #+#    #+#             */
/*   Updated: 2016/12/03 14:14:42 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void			ft_new_screen(t_struct *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
}

static void		init_raycast(t_struct *data)
{
	POS_X = 14.5;
	POS_Y = 16.5;
	DIRX = -1;
	DIRY = 0;
	PLANEX = 0;
	PLANEY = 1;
	SPEED = 0.1;
	ROT_SPEED = 0.12;
	MOOVE = 0;
	FAST = 0;
	TIME = 1;
	UN = 0;
	START = 0;
}

static int		parse_map(t_struct *data)
{
	int i;
	int	j;
	int k;

	i = -1;
	k = -1;
	while (MAP[0][++k])
		if (MAP[0][k] < '5')
			return (0);
	while (MAP[++i] && (k = -1))
	{
		j = ft_strlen(MAP[i]);
		while (MAP[i][++k])
		{
			if (MAP[i][k] < '0' || MAP[i][k] > '9')
				return (0);
		}
		if (j != Y_MAX || MAP[i][j - 1] < '5' || MAP[i][0] < '5')
			return (0);
	}
	k = -1;
	while (MAP[i - 1][++k])
		if (MAP[i - 1][k] < '5' || MAP[13][16] < '0' || MAP[13][16] > '1')
			return (0);
	return (1);
}

static void		recup_map(t_struct *data, char *map_name)
{
	char	*file;

	if (ft_strcmp(map_name, "map"))
	{
		ft_putstr("Wrong Map Name\n");
		exit(EXIT_FAILURE);
	}
	if (!(file = get_file(map_name)))
		exit(EXIT_SUCCESS);
	X_MAX = ft_lenchar(file, '\n');
	if (!(MAP = ft_strsplit(file, '\n')))
		exit(EXIT_FAILURE);
	Y_MAX = ft_strlen(MAP[0]);
	free(file);
	file = NULL;
	if (X_MAX < 14 || Y_MAX < 17 || !parse_map(data))
	{
		ft_putstr("Wrong Map\n");
		exit(EXIT_FAILURE);
	}
}

t_struct		*ft_init_struct(char *av)
{
	t_struct	*data;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		exit(EXIT_FAILURE);
	recup_map(data, av);
	WIDTH = 1200;
	HEIGHT = 800;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "Wolf3D");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	init_texture(data);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
	init_raycast(data);
	time(&TIMES);
	return (data);
}
