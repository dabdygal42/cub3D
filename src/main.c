/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:05:51 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/11 08:42:17 by akeryan          ###   ########.fr       */
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
	//print_map_2d(d.world_map, MAP_HEIGHT, MAP_WIDTH);
	render(&d);
	mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
	mlx_loop(d.mlx);
	return (EXIT_SUCCESS);
}
