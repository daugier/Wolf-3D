/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:32:42 by daugier           #+#    #+#             */
/*   Updated: 2016/11/11 23:18:08 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			get_texture(t_struct *data, int pixel)
{
	COLOR = WALL_DATA[I][pixel] + WALL_DATA[I][pixel + 1] *
		256 + WALL_DATA[I][pixel + 2] * 65536;
}

static void		init_wall_texture(t_struct *data)
{
	WALL[3] = mlx_xpm_file_to_image(MLX, "Texture/trump.xpm", &TEXT_WIDTH[3],
			&TEXT_HEIGHT[3]);
	WALL_DATA[3] = mlx_get_data_addr(WALL[3], &TEXT_BPP[3], &TEXT_SIZE_LINE[3],
			&ENDIAN);
	WALL[4] = mlx_xpm_file_to_image(MLX, "Texture/holland.xpm", &TEXT_WIDTH[4],
			&TEXT_HEIGHT[4]);
	WALL_DATA[4] = mlx_get_data_addr(WALL[4], &TEXT_BPP[4], &TEXT_SIZE_LINE[4],
			&ENDIAN);
	WALL[5] = mlx_xpm_file_to_image(MLX, "Texture/end.xpm", &TEXT_WIDTH[5],
			&TEXT_HEIGHT[5]);
	WALL_DATA[5] = mlx_get_data_addr(WALL[5], &TEXT_BPP[5], &TEXT_SIZE_LINE[5],
			&ENDIAN);
	WALL[6] = mlx_xpm_file_to_image(MLX, "Texture/holland.xpm", &TEXT_WIDTH[6],
			&TEXT_HEIGHT[6]);
	WALL_DATA[6] = mlx_get_data_addr(WALL[6], &TEXT_BPP[6], &TEXT_SIZE_LINE[6],
			&ENDIAN);
	WALL[2] = mlx_xpm_file_to_image(MLX, "Texture/tele.xpm", &TEXT_WIDTH[2],
			&TEXT_HEIGHT[2]);
	WALL_DATA[2] = mlx_get_data_addr(WALL[2], &TEXT_BPP[2], &TEXT_SIZE_LINE[2],
			&ENDIAN);
}

static void		init_floor_texture(t_struct *data)
{
	WALL[0] = mlx_xpm_file_to_image(MLX, "Texture/sol4.xpm", &TEXT_WIDTH[0],
			&TEXT_HEIGHT[0]);
	WALL_DATA[0] = mlx_get_data_addr(WALL[0], &TEXT_BPP[0], &TEXT_SIZE_LINE[0],
			&ENDIAN);
	WALL[1] = mlx_xpm_file_to_image(MLX, "Texture/end.xpm", &TEXT_WIDTH[1],
			&TEXT_HEIGHT[1]);
	WALL_DATA[1] = mlx_get_data_addr(WALL[1], &TEXT_BPP[1], &TEXT_SIZE_LINE[1],
			&ENDIAN);
}

static void		init_sky_texture(t_struct *data)
{
	WALL[8] = mlx_xpm_file_to_image(MLX, "Texture/42.xpm", &TEXT_WIDTH[8],
			&TEXT_HEIGHT[8]);
	WALL_DATA[8] = mlx_get_data_addr(WALL[8], &TEXT_BPP[8], &TEXT_SIZE_LINE[8],
			&ENDIAN);
}

void			init_texture(t_struct *data)
{
	if (!(WALL = (void**)malloc(sizeof(void*) * NB_TEXT)))
		return ;
	if (!(TEXT_BPP = (int*)malloc(sizeof(int) * NB_TEXT)))
		return ;
	if (!(TEXT_WIDTH = (int*)malloc(sizeof(int) * NB_TEXT)))
		return ;
	if (!(TEXT_HEIGHT = (int*)malloc(sizeof(int) * NB_TEXT)))
		return ;
	if (!(WALL_DATA = (char**)malloc(sizeof(char*) * NB_TEXT)))
		return ;
	if (!(TEXT_SIZE_LINE = (int*)malloc(sizeof(int) * NB_TEXT)))
		return ;
	init_wall_texture(data);
	init_floor_texture(data);
	init_sky_texture(data);
	WALL[10] = mlx_xpm_file_to_image(MLX, "Texture/gameover.xpm",
			&TEXT_WIDTH[10], &TEXT_HEIGHT[10]);
	WALL_DATA[10] = mlx_get_data_addr(WALL[10], &TEXT_BPP[10],
			&TEXT_SIZE_LINE[10], &ENDIAN);
	WALL[11] = mlx_xpm_file_to_image(MLX, "Texture/winner.xpm",
			&TEXT_WIDTH[11], &TEXT_HEIGHT[11]);
	WALL_DATA[11] = mlx_get_data_addr(WALL[11], &TEXT_BPP[11],
			&TEXT_SIZE_LINE[11], &ENDIAN);
}
