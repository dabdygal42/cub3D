/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:05:51 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/09 11:01:34 by akeryan          ###   ########.fr       */
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

	printf("pos_x: %d\n", (int)d.pos_x);
	printf("pos_y: %d\n", (int)d.pos_y);
	printf("val: %d\n", d.world_map[(int)d.pos_x][(int)d.pos_y]);

	print_map_2d(d.world_map, MAP_WIDTH, MAP_HEIGHT);
	render(&d);
	//print_map_1d(d.texture, TEX_HEIGHT, TEX_WIDTH);
	mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
	mlx_loop(d.mlx);
	return (EXIT_SUCCESS);
}
