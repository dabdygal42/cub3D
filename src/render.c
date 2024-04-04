/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:33:14 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/02 14:35:02 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_data *d)
{
	if (!d->img)
	{
		d->img = mlx_new_image(d->mlx, d->width, d->height);
		d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endi);
		d->buf_size = d->height * d->l_bytes;
	}
	ft_bzero(d->buf, d->buf_size);
	//draw_image
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}