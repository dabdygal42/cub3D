/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:03:12 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/15 23:03:56 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int key, t_data *d)
{
	if (key == KEY_W || key == KEY_S)
		w_s_keys(key, d);
	if (key == KEY_A || key == KEY_D)
		a_d_keys(key, d);
	if (key == KEY_LEFT_ARROW)
		left_arrow_key(key, d);
	if (key == KEY_RIGHT_ARROW)
		right_arrow_key(key, d);
	if (key == ESC)
		close_window();
	render(d);
	return (0);
}
