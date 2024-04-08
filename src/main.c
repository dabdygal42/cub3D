/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:05:51 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/08 17:59:24 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	d;
	
	(void) argc;
	(void) argv;
	init(&d);
	//print_map(d.world_map, MAP_WIDTH, MAP_HEIGHT);
	render(&d);
	print_map_1d(d.texture, TEX_HEIGHT, TEX_WIDTH);
	mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
	mlx_loop(d.mlx);
	return (EXIT_SUCCESS);
}
