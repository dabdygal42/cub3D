/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:45:50 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/07 21:12:55 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_vars2(t_data *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (d->pos_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0 - d->pos_x) * d->delta_dist_x;
	}
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->pos_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - d->pos_y) * d->delta_dist_y;
	}
}

static void	update_vars(int x, t_data *d)
{
	d->camera_x = 2 * x / (double) SCREEN_WIDTH -1;
	d->ray_dir_x = d->dir_x + d->plane_x * d->camera_x;
	d->ray_dir_y = d->dir_y + d->plane_y * d->camera_x;
	d->map_x = (int)d->pos_x;
	d->map_y = (int)d->pos_y;
	if (d->ray_dir_x == 0)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1 / d->ray_dir_x);
	if (d->ray_dir_y == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1 / d->ray_dir_y);
	update_vars2(d);
}

static void dda(t_data *d)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->world_map[d->map_x][d->map_y] > 0)
			hit = 1;
	}
}

void	run(t_data *d)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		update_vars(x, d);
		dda(d);
	}
}