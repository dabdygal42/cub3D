/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:05:51 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/09 14:24:00 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

static void	init_content(t_g_assets *content)
{
	content->no = NULL;
	content->so = NULL;
	content->we = NULL;
	content->ea = NULL;
	content->floor_rgb[0] = -1;
	content->floor_rgb[1] = -1;
	content->floor_rgb[2] = -1;
	content->ceil_rgb[0] = -1;
	content->ceil_rgb[1] = -1;
	content->ceil_rgb[2] = -1;
}

int	main(int argc, char *argv[])
{
	t_data		d;
	t_g_assets	content;

	init_content(&content);
	if (parse(argc, argv, &content) <= 0)
		return (EXIT_FAILURE);
	init(&d);
	mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
	mlx_loop(d.mlx);

	return (EXIT_SUCCESS);
}
