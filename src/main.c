/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:05:51 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/16 14:38:04 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"
#include <stdio.h>
#include <errno.h>

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
	content->map = NULL;
	content->rowlist = NULL;
	content->row_qty = 0;
	content->col_qty = 0;
}

static void	print_content(t_g_assets *c)
{
	int	i;
	int	j;

	printf("North Texture	\"%s\"\n", c->no);
	printf("South Texture	\"%s\"\n", c->so);
	printf("West Texture	\"%s\"\n", c->we);
	printf("East Texture	\"%s\"\n", c->ea);
	printf("Floor color:	%i, %i, %i\n", c->floor_rgb[0], c->floor_rgb[1], c->floor_rgb[2]);
	printf("Ceiling color:	%i, %i, %i\n", c->ceil_rgb[0], c->ceil_rgb[1], c->ceil_rgb[2]);
	printf("MAP:\n");
	i = 0;
	while (i < c->row_qty)
	{
		j = 0;
		while (j < c->col_qty)
		{
			printf("%c", c->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data		d;
	t_g_assets	content;

	errno = 0;
	init_content(&content);
	if (parse(argc, argv, &content) <= 0)
		return (EXIT_FAILURE);
	print_content(&content);
	init(&d);
	mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
	mlx_loop(d.mlx);

	return (EXIT_SUCCESS);
}
