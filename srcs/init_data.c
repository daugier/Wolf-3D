/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:15:06 by daugier           #+#    #+#             */
/*   Updated: 2016/10/06 17:19:12 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_text			*init_texture(t_struct *data)
{
	t_text *texture;

	if (!(texture = (t_text *)ft_memalloc(sizeof(t_text))))
		exit(EXIT_FAILURE);
	WALL_ONE = mlx_xpm_file_to_image(MLX, "../textute/wall_one.xpm", &WALL_ONE_X, &WALL_ONE_Y);
	WALLADD = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE_WALL, & ENDIAN);
	return (texture);
}

t_raycast	*init_raycast(t_struct *data)
{
	t_raycast *raycast;

	if (!(raycast = (t_raycast *)ft_memalloc(sizeof(t_raycast))))
		exit(EXIT_FAILURE);
	POS_X = 5;
	POS_Y = 5;
	DIRX = -1;
	DIRY = 0;
	PLANEX = 0;
	PLANEY = 1;
	SPEED = 0.1;
	ROT_SPEED = 0.04;
	MOOVE = 0;
	JUMP = 0;
	SIT = 0;
	FAST = 0;
	return (raycast);
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
	t_raycast	*raycast;
	t_text		*texture;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		exit(EXIT_FAILURE);
	recup_map(data, av);
	WIDTH = 1200;
	HEIGHT = 800;
	texture = init_texture(data);
	raycast = init_raycast(data);
	BPP = 24;
	ENDIAN = 1;
	SIZE_LINE = WIDTH * (BPP / 8);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "Wolf3D");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
	return (data);
}
