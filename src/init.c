/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:20:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/02 17:13:33 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_data *d)
{
	d->width = WINDOW_WIDTH;
	d->height = WINDOW_HEIGHT;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "CUB3D");
	d->img = NULL;
}