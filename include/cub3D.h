/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:57:14 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/08 18:38:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define SCREEN_WIDTH	640	
# define SCREEN_HEIGHT	480	
# define TEX_WIDTH		32	
# define TEX_HEIGHT		32	
# define MAP_WIDTH		24
# define MAP_HEIGHT		24

# define ESC		53
# define KEY_7		89	
# define KEY_8		91
# define KEY_UP		13
# define KEY_DOWN	1
# define KEY_LEFT	0
# define KEY_RIGHT	2

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		pix_bits;
	int		l_bytes;
	int		endi;
	void	*img;
	char	*buf;
	int		buf_size;
	int		map_width;
	int		map_heigth;
	int		screen_width;
	int		screen_height;
	int		**world_map;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;	
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		pitch;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		*texture;
}	t_data;

void		init(t_data *d);
void		render(t_data *d);
void		run_dda(t_data *d);

//hooks
int			close_window(void);
int			key_handler(int key, t_data *d);

//utils
void		print_map_2d(int **arr, int rows, int cols);
void		print_map_1d(int *arr, int cols, int rows);

#endif
