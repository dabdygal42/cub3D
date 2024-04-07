/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:33:14 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/07 21:10:44 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_image(t_data *d)
{
	if (d->side == 0)
		d->perp_wall_dist = d->side_dist_x - d->delta_dist_x;
	else
		d->perp_wall_dist = d->side_dist_y - d->delta_dist_y;
}

void	render(t_data *d)
{
	if (!d->img)
	{
		d->img = mlx_new_image(d->mlx, d->screen_width, d->screen_height);
		d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endi);
		d->buf_size = d->screen_height * d->l_bytes;
	}
	//ft_bzero(d->buf, d->buf_size);
	draw_image(d);
	//mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}