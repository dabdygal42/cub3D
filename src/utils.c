/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:08:31 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/15 22:55:10 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_dda(t_data *d)
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

LONG	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (error_msg("gettimeofday() failed in get_time()\n", NULL));
	return ((tv.tv_sec * (LONG)1000) + (tv.tv_usec / 1000));
}

int	error_msg(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		destroy(data);
	return (1);
}

void	destroy(t_data *d)
{
	(void)d;
	return ;
}