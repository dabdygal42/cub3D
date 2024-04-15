/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:33:14 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/15 22:48:04 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	update_vars(int x, t_data *d)
{
	d->camera_x = 2 * x / (double) SCREEN_WIDTH - 1;
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

static void	fill_img_buffer(t_data *d, int x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		pix;

	y = d->draw_start;
	step = 1.0 * (int)TEX_HEIGHT / d->line_height;
	tex_pos = (d->draw_start - d->view_shift - d->screen_height \
		/ 2 + d->line_height / 2) * step;
	while (y < d->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		pix = y * d->l_bytes + x * 4;
		d->buf[pix + 0] = d->texture[0]->buf[d->texture[0]->l_bytes * tex_y + \
			d->tex_x * 4];
		d->buf[pix + 1] = d->texture[0]->buf[d->texture[0]->l_bytes * tex_y + \
			d->tex_x * 4 + 1];
		d->buf[pix + 2] = d->texture[0]->buf[d->texture[0]->l_bytes * tex_y + \
			d->tex_x * 4 + 2];
		d->buf[pix + 3] = d->texture[0]->buf[d->texture[0]->l_bytes * tex_y + \
			d->tex_x * 4 + 3];
		y++;
	}
}

void	draw_strip(t_data *d, int x)
{
	d->tex_num = d->world_map[d->map_x][d->map_y] - 1;
	if (d->side == 0)
		d->wall_x = d->pos_y + d->perp_wall_dist * d->ray_dir_y;
	else
		d->wall_x = d->pos_x + d->perp_wall_dist * d->ray_dir_x;
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * (double)TEX_WIDTH);
	if (d->side == 0 && d->ray_dir_x > 0)
		d->tex_x = (int)TEX_WIDTH - d->tex_x - 1;
	if (d->side == 1 && d->ray_dir_y < 0)
		d->tex_x = (int)TEX_WIDTH - d->tex_x - 1;
	fill_img_buffer(d, x);
}
