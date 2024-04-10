/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:20:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/10 09:45:18 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int **map_init()
{
	int	**outmap;	
	int	i;

	int map[MAP_HEIGHT][MAP_WIDTH]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
		{1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1},
		{1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		{1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1},
		{1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
		{1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
		{1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};	
	outmap = (int **)malloc(MAP_HEIGHT * sizeof(int *));
	if (outmap == NULL)
	{
		printf("malloc failed in map_init\n");
		free (outmap);
		return (NULL);
	}
	i = -1;
	while (++i < MAP_HEIGHT)
	{
		outmap[i] = (int *)malloc(MAP_WIDTH * sizeof(int));
		if (outmap[i] == NULL)
		{
			printf("malloc failed in map_init\n");
			while (--i > 0)
				free(outmap[i]);
			free(outmap);
			return (NULL);
		}
		ft_memcpy(outmap[i], map[i], sizeof(map[i]));
	}
	return (outmap);
}

static int	*init_texture(void)
{
	int	*texture;
	int	x, y;
	int	ycolor;

	texture = (int *)malloc(TEX_WIDTH * TEX_HEIGHT * sizeof(int));
	if (texture == NULL)
	{
		printf("Memory allocation failed in init_texture()\n");
		return (NULL);
	}
	x = -1;
	y = -1;
	ycolor = 0;
	while (++x < TEX_WIDTH)
	{
		while (++y < TEX_HEIGHT)
		{
			ycolor = y * 256 / TEX_HEIGHT;
			//ycolor++;
			texture[TEX_WIDTH * y + x] = 100;
		}
		y = -1;
	}
	return (texture);
}

void	init(t_data *d)
{
	d->map_width = MAP_WIDTH;
	d->map_heigth = MAP_HEIGHT;
	d->screen_height = SCREEN_HEIGHT;
	d->screen_width = SCREEN_WIDTH;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, SCREEN_WIDTH, d->screen_height, "CUB3D");
	d->img = NULL;
	d->world_map = map_init();
	d->pos_x = 21.0;
	d->pos_y = 11.5;
	d->dir_x = -1.0;
	d->dir_y = 0.0;
	d->plane_x = 0.0;
	d->plane_y = 0.7;
	d->time = get_time();
	d->view_shift = 100;
	d->texture = init_texture();
}
