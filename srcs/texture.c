/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:32:42 by daugier           #+#    #+#             */
/*   Updated: 2016/10/24 23:26:06 by daugier          ###   ########.fr       */
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
	//floor
	WALL[0] = mlx_xpm_file_to_image(MLX, "Texture/floor3.xpm", &TEXT_WIDTH[0], &TEXT_HEIGHT[0]);
	WALL_DATA[0] = mlx_get_data_addr(WALL[0], &TEXT_BPP[0], &TEXT_SIZE_LINE[0], &ENDIAN);
	WALL[1] = mlx_xpm_file_to_image(MLX, "Texture/end.xpm", &TEXT_WIDTH[1], &TEXT_HEIGHT[1]);
	WALL_DATA[1] = mlx_get_data_addr(WALL[1], &TEXT_BPP[1], &TEXT_SIZE_LINE[1], &ENDIAN);
	
	//wall
	WALL[3] = mlx_xpm_file_to_image(MLX, "Texture/exte.xpm", &TEXT_WIDTH[3], &TEXT_HEIGHT[3]);
	WALL_DATA[3] = mlx_get_data_addr(WALL[3], &TEXT_BPP[3], &TEXT_SIZE_LINE[3], &ENDIAN);
	
	WALL[4] = mlx_xpm_file_to_image(MLX, "Texture/exte.xpm", &TEXT_WIDTH[4], &TEXT_HEIGHT[4]);
	WALL_DATA[4] = mlx_get_data_addr(WALL[4], &TEXT_BPP[4], &TEXT_SIZE_LINE[4], &ENDIAN);
	WALL[5] = mlx_xpm_file_to_image(MLX, "Texture/end.xpm", &TEXT_WIDTH[5], &TEXT_HEIGHT[5]);
	WALL_DATA[5] = mlx_get_data_addr(WALL[5], &TEXT_BPP[5], &TEXT_SIZE_LINE[5], &ENDIAN);
	
	//ciel
	WALL[8] = mlx_xpm_file_to_image(MLX, "Texture/ciel3.xpm", &TEXT_WIDTH[8], &TEXT_HEIGHT[8]);
	WALL_DATA[8] = mlx_get_data_addr(WALL[8], &TEXT_BPP[8], &TEXT_SIZE_LINE[8], &ENDIAN);
	WALL[9] = mlx_xpm_file_to_image(MLX, "Texture/lune.xpm", &TEXT_WIDTH[9], &TEXT_HEIGHT[9]);
	WALL_DATA[9] = mlx_get_data_addr(WALL[9], &TEXT_BPP[9], &TEXT_SIZE_LINE[9], &ENDIAN);
	
	//looser
	WALL[10] = mlx_xpm_file_to_image(MLX, "Texture/looser2.xpm", &TEXT_WIDTH[10], &TEXT_HEIGHT[10]);
	WALL_DATA[10] = mlx_get_data_addr(WALL[10], &TEXT_BPP[10], &TEXT_SIZE_LINE[10], &ENDIAN);
	WALL[11] = mlx_xpm_file_to_image(MLX, "Texture/end2.xpm", &TEXT_WIDTH[11], &TEXT_HEIGHT[11]);
	WALL_DATA[11] = mlx_get_data_addr(WALL[11], &TEXT_BPP[11], &TEXT_SIZE_LINE[11], &ENDIAN);
}

