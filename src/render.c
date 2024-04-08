/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:33:14 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/08 10:05:17 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_start_end(t_data *d)
{
	if (d->side == 0)
		d->perp_wall_dist = d->side_dist_x - d->delta_dist_x;
	else
		d->perp_wall_dist = d->side_dist_y - d->delta_dist_y;
	d->line_height = (int)(d->screen_height / d->perp_wall_dist);
	d->draw_start = -d->line_height / 2 + d->screen_height / 2 + d->pitch;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + d->screen_height / 2 + d->pitch;
	if (d->draw_end >= d->screen_height)
		d->draw_end = d->screen_height - 1;
}


static void	update_vars_(t_data *d)
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
	update_vars_(d);
}


void	render(t_data *d)
{
	int	x;

	x = 0;
	if (!d->img)
	{
		d->img = mlx_new_image(d->mlx, d->screen_width, d->screen_height);
		d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endi);
		d->buf_size = d->screen_height * d->l_bytes;
	}
	ft_bzero(d->buf, d->buf_size);
	while (x < SCREEN_WIDTH)
	{
		update_vars(x, d);
		run_dda(d);
		calc_start_end(d);
		x++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}