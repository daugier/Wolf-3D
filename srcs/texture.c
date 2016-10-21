/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:32:42 by daugier           #+#    #+#             */
/*   Updated: 2016/10/21 23:23:21 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_texture(t_struct *data)
{
	WALL = (void**)malloc(sizeof(void*) * NB_TEXT);
	TEXT_BPP = (int*)malloc(sizeof(int) * NB_TEXT);
	TEXT_WIDTH = (int*)malloc(sizeof(int) * NB_TEXT);
	TEXT_HEIGHT = (int*)malloc(sizeof(int) * NB_TEXT);
	WALL_DATA = (char**)malloc(sizeof(char*) * NB_TEXT);
	TEXT_SIZE_LINE = (int*)malloc(sizeof(int) * NB_TEXT);
	WALL[0] = mlx_xpm_file_to_image(MLX, "Texture/1.xpm", &TEXT_WIDTH[0], &TEXT_HEIGHT[0]);
	WALL_DATA[0] = mlx_get_data_addr(WALL[0], &TEXT_BPP[0], &TEXT_SIZE_LINE[0], &ENDIAN);
	WALL[1] = mlx_xpm_file_to_image(MLX, "Texture/2.xpm", &TEXT_WIDTH[1], &TEXT_HEIGHT[1]);
	WALL_DATA[1] = mlx_get_data_addr(WALL[1], &TEXT_BPP[1], &TEXT_SIZE_LINE[1], &ENDIAN);
	WALL[2] = mlx_xpm_file_to_image(MLX, "Texture/3.xpm", &TEXT_WIDTH[2], &TEXT_HEIGHT[2]);
	WALL_DATA[2] = mlx_get_data_addr(WALL[2], &TEXT_BPP[2], &TEXT_SIZE_LINE[2], &ENDIAN);
	WALL[3] = mlx_xpm_file_to_image(MLX, "Texture/4.xpm", &TEXT_WIDTH[3], &TEXT_HEIGHT[3]);
	WALL_DATA[3] = mlx_get_data_addr(WALL[3], &TEXT_BPP[3], &TEXT_SIZE_LINE[3], &ENDIAN);
	WALL[4] = mlx_xpm_file_to_image(MLX, "Texture/5.xpm", &TEXT_WIDTH[4], &TEXT_HEIGHT[4]);
	WALL_DATA[4] = mlx_get_data_addr(WALL[4], &TEXT_BPP[4], &TEXT_SIZE_LINE[4], &ENDIAN);
	WALL[5] = mlx_xpm_file_to_image(MLX, "Texture/6.xpm", &TEXT_WIDTH[5], &TEXT_HEIGHT[5]);
	WALL_DATA[5] = mlx_get_data_addr(WALL[5], &TEXT_BPP[5], &TEXT_SIZE_LINE[5], &ENDIAN);
	WALL[6] = mlx_xpm_file_to_image(MLX, "Texture/1.xpm", &TEXT_WIDTH[6], &TEXT_HEIGHT[6]);
	WALL_DATA[6] = mlx_get_data_addr(WALL[6], &TEXT_BPP[6], &TEXT_SIZE_LINE[6], &ENDIAN);
	WALL[7] = mlx_xpm_file_to_image(MLX, "Texture/3.xpm", &TEXT_WIDTH[7], &TEXT_HEIGHT[7]);
	WALL_DATA[7] = mlx_get_data_addr(WALL[7], &TEXT_BPP[7], &TEXT_SIZE_LINE[7], &ENDIAN);
}

