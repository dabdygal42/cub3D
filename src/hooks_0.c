/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:19:38 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/17 17:42:19 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	right_arrow_key(int key, t_data *d)
{
	if (key == KEY_RIGHT_ARROW)
		rotate_right(d, d->rot_speed);
}

void	left_arrow_key(int key, t_data *d)
{
	if (key == KEY_LEFT_ARROW)
		rotate_left(d, d->rot_speed);
}

void	w_s_keys(int key, t_data *d)
{
	if (key == KEY_W)
	{
		if (d->world_map[(int)(d->pos_x + d->dir_x * \
			d->move_speed)][(int)d->pos_y] == 48)
			d->pos_x += d->dir_x * d->move_speed;
		if (d->world_map[(int)d->pos_x][(int)(d->pos_y + \
			d->dir_y * d->move_speed)] == 48)
			d->pos_y += d->dir_y * d->move_speed;
	}
	if (key == KEY_S)
	{
		if (d->world_map[(int)(d->pos_x - d->dir_x * \
			d->move_speed)][(int)d->pos_y] == 48)
			d->pos_x -= d->dir_x * d->move_speed;
		if (d->world_map[(int)d->pos_x][(int)(d->pos_y - d->dir_y * \
		d->move_speed)] == 48)
			d->pos_y -= d->dir_y * d->move_speed;
	}
}

void	a_d_keys(int key, t_data *d)
{
	if (key == KEY_D)
	{
		if (d->world_map[(int)(d->pos_x + d->plane_x * \
		d->move_speed)][(int)d->pos_y] == 48)
			d->pos_x += d->plane_x * d->move_speed;
		if (d->world_map[(int)d->pos_x][(int)(d->pos_y + \
			d->plane_y * d->move_speed)] == 48)
			d->pos_y += d->plane_y * d->move_speed;
	}
	if (key == KEY_A)
	{
		if (d->world_map[(int)(d->pos_x - d->plane_x * \
			d->move_speed)][(int)d->pos_y] == 48)
			d->pos_x -= d->plane_x * d->move_speed;
		if (d->world_map[(int)d->pos_x][(int)(d->pos_y - \
			d->plane_y * d->move_speed)] == 48)
			d->pos_y -= d->plane_y * d->move_speed;
	}
}

int	close_window(void)
{
	exit(0);
	return (0);
}
