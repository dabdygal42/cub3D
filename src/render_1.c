/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:14:51 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/12 14:13:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_move_rot_speeds(t_data *d)
{
	d->old_time = d->time;
	d->time = get_time();
	d->frame_time = (d->time - d->old_time) / 1000.0;
	d->move_speed = d->frame_time * 50.0;
	d->rot_speed = d->frame_time * 30.0;
}

void	plot(int x, int y, t_data *d, int color)
{
	int	pix;

	pix = (y * d->l_bytes) + (x * 4);
	if (x >= 0 && x * 4 < d->l_bytes && y >= 0 && pix < d->buf_size)
	{
		if (d->endi == 1)
		{
			d->buf[pix + 0] = (color >> 24);
			d->buf[pix + 1] = (color >> 16) & 0xFF;
			d->buf[pix + 2] = (color >> 8) & 0xFF;
			d->buf[pix + 3] = (color) & 0xFF;
		}
		else
		{
			d->buf[pix + 0] = (color) & 0xFF;
			d->buf[pix + 1] = (color >> 8) & 0xFF;
			d->buf[pix + 2] = (color >> 16) & 0xFF;
			d->buf[pix + 3] = (color >> 24);
		}
	}
}
