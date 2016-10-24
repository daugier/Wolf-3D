/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:15:06 by daugier           #+#    #+#             */
/*   Updated: 2016/10/25 00:14:53 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		init_raycast(t_struct *data)
{
	POS_X = 2;
	POS_Y = 16;
	DIRX = -1;
	DIRY = 0;
	PLANEX = 0;
	PLANEY = 1;
	SPEED = 0.1;
	ROT_SPEED = 0.07;
	MOOVE = 0;
	FAST = 0;
	TIME = 1;
}

void			ft_new_screen(t_struct *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
}

static void		recup_map(t_struct *data, char *map_name)
{
	int		x;
	char	*file;


	if (!(file = get_file(map_name)))
		exit(EXIT_SUCCESS);
	X_MAX = ft_lenchar(file, '\n');
	if (!(MAP = ft_strsplit(file, '\n')))
		exit(EXIT_FAILURE);
	Y_MAX = ft_strlen(MAP[0]);
	free(file);
	file = NULL;
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
