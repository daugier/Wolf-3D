/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 18:44:42 by daugier           #+#    #+#             */
/*   Updated: 2016/10/25 18:29:21 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		write_score(t_struct *data, char *end)
{
	int	color;
	int		fd;
	char	*str;
	char	*tmp;
	
	fd = open("score.txt", O_RDWR, O_APPEND);
	ft_putstr_fd("DODO : ", fd);
	ft_putstr_fd(end, fd);
	ft_putendl_fd("Seconde", fd);
	color = 0xA633;
	end = get_file("score.txt");
	mlx_string_put(MLX, WIN, 5, 50, color, end);
}

void		display_looser(t_struct *data)
{
	int	color;

	color = 0xFF0000;
	mlx_string_put(MLX, WIN, 5, 5, color, "YOU LOOOOOOOSE ! YOU ARE A LOOSER !! NOOB ");
	color = 0xA633;
	mlx_string_put(MLX, WIN, 900, 5, color, "Press ENTER for retry ");
	mlx_string_put(MLX, WIN, 900, 25, color, "Press ESCAPE for quit ");
}

void		display_win(t_struct *data, char *end)
{
	int	color;

	color = 0xA633;
	mlx_string_put(MLX, WIN, 5, 5, color, "GREAT JOB ! only ");
	mlx_string_put(MLX, WIN, 185, 5, color, end);
	mlx_string_put(MLX, WIN, 215, 5, color, "Second ! ");
	mlx_string_put(MLX, WIN, 900, 5, color, "Press ENTER for retry ");
	mlx_string_put(MLX, WIN, 900, 25, color, "Press ESCAPE for quit ");
//	write_score(data, end);
}

void		display_end(t_struct *data, int i)
{
	int x;
	int y;
	int color;
	int	pixel;

	x = -1;
	while (++x < WIDTH && (y = -1))
		while (++y < HEIGHT)
		{
			pixel = y * TEXT_SIZE_LINE[i] + x * (TEXT_BPP[i] / 8);
			color = WALL_DATA[i][pixel] + WALL_DATA[i][pixel + 1] * 256 + WALL_DATA[i][pixel + 2] * 65536;
			if (TIME == 0)
				color &= RED;
			write_data_pixel(data, x, y, color);
		}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	info(data);
}

void		info(t_struct *data)
{
	time_t						tmp;
	char						*c;
	int							color;
	int							x;
	int							y;
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
	{
		mlx_string_put(MLX, WIN, 5, 5, color, "Time : ");
		mlx_string_put(MLX, WIN, 70, 5, color, c);
	}
	free(c);
	free(end);
}
