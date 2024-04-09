/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:19:38 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/09 21:38:37 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int key, t_data *d)
{
	if (key == ESC)
		close_window();
	if (key == KEY_UP)
	{
		if (d->world_map[(int)(d->pos_x + d->dir_x * d->move_speed)][(int)d->pos_y] == 0)
			d->pos_x += d->dir_x * d->move_speed;
		if (d->world_map[(int)d->pos_x][(int)(d->pos_y + d->dir_y * d->move_speed)] == 0)
			d->pos_y += d->dir_y * d->move_speed;
	}
	if (key == KEY_DOWN)
		d->pos_x += 1;
	if (key == KEY_LEFT)
		d->pos_y -= 1;
	if (key == KEY_RIGHT)
		d->pos_y += 1;
	render(d);
	return (0);
}

int	close_window(void)
{
	exit(0);
	return (0);
}
