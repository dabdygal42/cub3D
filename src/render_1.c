/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:14:51 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/10 09:36:34 by akeryan          ###   ########.fr       */
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
	printf("frame time: %.4Lf\n", d->frame_time);
	printf("fps: %.4Lf\n", 1 / d->frame_time);
}
