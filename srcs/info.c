/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 21:55:15 by daugier           #+#    #+#             */
/*   Updated: 2016/11/09 11:04:31 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			display_end(t_struct *data, int i)
{
	int	x;
	int y;
	int color;
	int	pixel;

	x = -1;
	while (++x < WIDTH && (y = -1))
		while (++y < HEIGHT)
		{
			pixel = y * TEXT_SIZE_LINE[i] + x * (TEXT_BPP[i] / 8);
			color = WALL_DATA[i][pixel] + WALL_DATA[i][pixel + 1] * 256 +
				WALL_DATA[i][pixel + 2] * 65536;
			write_data_pixel(data, x, y, color);
		}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	info(data);
}

static void		display_time(t_struct *data, char *c, int color)
{
	mlx_string_put(MLX, WIN, 5, 5, color, "Time : ");
	mlx_string_put(MLX, WIN, 70, 5, color, c);
}

static void		display_looser(t_struct *data)
{
	int		color;
	time_t	times;

	color = 0xA633;
	time(&times);
	if (times % 2 == 0)
	{
		mlx_string_put(MLX, WIN, 500, 625, color, "Press ENTER for retry ");
		mlx_string_put(MLX, WIN, 500, 650, color, "Press ESCAPE for quit ");
	}
}

static void		display_win(t_struct *data, char *end)
{
	int		color;
	time_t	times;

	color = 0xA633;
	mlx_string_put(MLX, WIN, 5, 35, color, "GREAT JOB ! only ");
	mlx_string_put(MLX, WIN, 185, 35, color, end);
	mlx_string_put(MLX, WIN, 215, 35, color, "Second ! ");
	time(&times);
	if (times % 2 == 0)
	{
		mlx_string_put(MLX, WIN, 900, 35, color, "Press ENTER for retry ");
		mlx_string_put(MLX, WIN, 900, 55, color, "Press ESCAPE for quit ");
	}
}

void			info(t_struct *data)
{
	time_t						tmp;
	char						*c;
	int							color;
	char						*end;

	color = 0xFFFFFF;
	time(&tmp);
	if ((60 - tmp + TIMES) >= 0 && MAP[(int)POS_X][(int)POS_Y] != '1')
		TIME = 60 - tmp + TIMES;
	c = ft_itoa(TIME);
	tmp = 60 - TIME;
	end = ft_itoa(tmp);
	if ((TIME <= 10 && TIME % 2 == 0) || TIME == 0)
		color = 0xFF0000;
	if (MAP[(int)POS_X][(int)POS_Y] == '1' && TIME > 0)
		display_win(data, end);
	else if (TIME == 0)
		display_looser(data);
	else
		display_time(data, c, color);
	free(end);
	free(c);
}
