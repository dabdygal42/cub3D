/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:19:38 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/10 09:41:38 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int key, t_data *d)
{
	double	old_dir;
	double	old_plane_x;

	printf("key num: %d\n", key);

	if (key == ESC)
		close_window();
	if (key == KEY_W)
	{
		if (d->world_map[(int)(d->pos_x + d->dir_x * d->move_speed)][(int)d->pos_y] == 0)
			d->pos_x += d->dir_x * d->move_speed;
		if (d->world_map[(int)d->pos_x][(int)(d->pos_y + d->dir_y * d->move_speed)] == 0)
			d->pos_y += d->dir_y * d->move_speed;
	}
	if (key == KEY_S)
	{
		if (d->world_map[(int)(d->pos_x - d->dir_x * d->move_speed)][(int)d->pos_y] == 0)
			d->pos_x -= d->dir_x * d->move_speed;
		if (d->world_map[(int)d->pos_x][(int)(d->pos_y - d->dir_y * d->move_speed)] == 0)
			d->pos_y -= d->dir_y * d->move_speed;
	}
	if (key == KEY_LEFT_ARROW)
	{
		old_dir = d->dir_x;
		d->dir_x = d->dir_x * cos(d->rot_speed) - d->dir_y * sin(d->rot_speed);
		d->dir_y = d->dir_x * sin(d->rot_speed) + d->dir_y * cos(d->rot_speed);
		old_plane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(d->rot_speed) - d->plane_y * sin(d->rot_speed);
		d->plane_y = old_plane_x * sin(d->rot_speed) + d->plane_y * cos(d->rot_speed);
	}
	if (key == KEY_RIGHT_ARROW)
	{
		old_dir = d->dir_x;
		d->dir_x = d->dir_x * cos(-d->rot_speed) - d->dir_y * sin(-d->rot_speed);
		d->dir_y = old_dir * sin(-d->rot_speed) + d->dir_y * cos(-d->rot_speed);
		old_plane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(-d->rot_speed) - d->plane_y * sin(-d->rot_speed);
		d->plane_y = old_plane_x * sin(-d->rot_speed) + d->plane_y * cos(-d->rot_speed);
	}
	render(d);
	return (0);
}

int	close_window(void)
{
	exit(0);
	return (0);
}
