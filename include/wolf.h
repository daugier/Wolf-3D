/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 18:13:26 by daugier           #+#    #+#             */
/*   Updated: 2016/10/06 17:06:57 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include <OpenCL/opencl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include "../libs/libft/includes/libft.h"

# define RED 0xFF0000
# define DARKKHAKI 0xB8B868
# define GREEN 0x00FF00
# define ORANGE 0xFF6600
# define GRAY 0x808080
# define GOLDENROD 0xFFD800
# define MAROON 0x800000

/*define moovement*/

# define WALK (1 << 0)
# define BACK (1 << 1)
# define LEFT (1 << 2)
# define RIGHT (1 << 3)
# define TURN_RIGHT (1 << 4)
# define TURN_LEFT (1 << 5)

/*define structure raycast*/

# define SPEED data->raycast.speed
# define POS_X data->raycast.pos_x
# define POS_Y data->raycast.pos_y
# define DIRX data->raycast.dirx
# define DIRY data->raycast.diry
# define PLANEX data->raycast.planex
# define PLANEY data->raycast.planey
# define W data->raycast.w
# define H data->raycast.h
# define RAYDIR_X data->raycast.raydir_x
# define RAYDIR_Y data->raycast.raydir_y
# define RAYPOS_X data->raycast.raypos_x
# define RAYPOS_Y data->raycast.raypos_y
# define CAM_X data->raycast.camera_x
# define SIZEDIST_X data->raycast.sizedist_x
# define SIZEDIST_Y data->raycast.sizedist_y
# define DELTADIST_X data->raycast.deltadist_x
# define DELTADIST_Y data->raycast.deltadist_y
# define PERPWALLDIST data->raycast.perpwalldist
# define HIT data->raycast.hit
# define STEP_X data->raycast.step_x
# define STEP_Y data->raycast.step_y
# define SIDE data->raycast.side
# define SIDEDIST_X data->raycast.sidedist_x
# define SIDEDIST_Y data->raycast.sidedist_y
# define DRAWSTART data->raycast.drawstart
# define DRAWEND data->raycast.drawend
# define ROT_SPEED data->raycast.rotspeed
# define H_LINE data->raycast.h_line
# define TIME data->raycast.time
# define OLD_TIME data->raycast.old_time

/*define structure data*/

# define OLD_DRAWEND data->old_drawend
# define SIT data->sit
# define JUMP data->jump
# define FAST data->fast
# define MOOVE data->moove
# define MAP_X data->map_x
# define MAP_Y data->map_y
# define FILES data->file
# define X_MAX data->x_max
# define Y_MAX data->y_max
# define MAP data->map
# define HEIGHT data->height
# define WIDTH data->width
# define X data->x
# define Y data->y
# define SIZE_LINE data->size_line
# define BPP data->bit_per_pixel
# define ENDIAN data->endian
# define DATA data->data
# define COLOR data->color_value
# define MLX data->mlx
# define WIN data->win
# define IMG data->img


/*define texture*/

# define WALL_ONE data->texture.wall_one
# define WALL_TWO data->texture.wall_two
# define WALL_ONE_X data->texture.wall_one_x
# define WALL_ONE_Y data->texture.wall_one_y
# define SIZE_LINE_WALL data->texture.size_line_wall
# define WALLADD data->texture.walladd

typedef struct	s_text
{
	void					*wall_one;
	void					*wall_two;
	char					*walladd;
	int						wall_one_y;
	int						wall_one_x;
	int						size_line_wall;
}
				t_text;

typedef struct	s_raycast
{
	double					speed;
	double					rotspeed;
	double					pos_x;
	double					pos_y;
	double					dirx;
	double					diry;
	double					planex;
	double					planey;
	double					raydir_x;
	double					raydir_y;
	double					raypos_x;
	double					raypos_y;
	double					camera_x;
	double					sizedist_x;
	double					sizedist_y;
	double					deltadist_x;
	double					deltadist_y;
	double					perpwalldist;
	double					hit;
	double					time;
	double					old_time;
	int					step_x;
	int					step_y;
	int					side;
	double				sidedist_x;
	double				sidedist_y;
	int					drawstart;
	int					drawend;
	int					h_line;
}				t_raycast;

typedef struct	s_struct
{
	int					old_drawend;
	int					jump;
	int					fast;
	int					sit;
	int					moove;
	int					map_x;
	int					map_y;
	int					x_max;
	int					y_max;
	char				**map;
	int					width;
	int					height;
	int					x;
	int					y;
	int					size_line;
	int					bit_per_pixel;
	int					endian;
	char				*data;
	unsigned long int	color_value;
	void				*mlx;
	void				*win;
	void				*img;
	t_text				texture;
	t_raycast			raycast;
}				t_struct;

int					key_func_bis(int keycode, t_struct *data);
int					mouse_func(int button, int x, int y, t_struct *data);
void				ft_rotate_left(t_struct *data);
void				ft_rotate_right(t_struct *data);
void				ft_left(t_struct *data);
void				ft_right(t_struct *data);
void				ft_moove(t_struct *data);
void				ft_back(t_struct *data);
void				ft_walk(t_struct *data);
void				ft_turn(t_struct *data);
void				ft_new_screen(t_struct *data);
void				write_data_pixel(t_struct *data, int x, int y, int color);
void				ray_cast_wall(t_struct *data, int x);
int					wolf(t_struct *data);
t_struct			*ft_init_struct(char *av);
int					key_func(int keycode, t_struct *data);
void				free_all(t_struct *data);

#endif
