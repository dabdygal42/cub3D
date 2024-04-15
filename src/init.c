/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:20:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/15 22:39:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	**map_init(void)
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

t_texture	**init_texture(t_data *d, char **path)
{
	t_texture	**tex;
	int			i;

	tex = (t_texture **)malloc(sizeof(t_texture *) * 4);
	i = -1;
	while (++i < 4)
		tex[i] = (t_texture *)malloc(sizeof(t_texture));
	i = -1;
	while (++i < 4)
	{
		tex[i]->path = path[i];
		tex[i]->img = mlx_xpm_file_to_image(d->mlx, path[i], \
			&tex[i]->width, &tex[i]->height);
		tex[i]->buf = mlx_get_data_addr(tex[i]->img, &tex[i]->pix_bits, \
			&tex[i]->l_bytes, &tex[i]->endi);
	}
	return (tex);
}

void	init(t_data *d, char **path)
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
	d->view_shift = 0;
	d->ceiling_color = 0x6fecf7;
	d->floor_color = 0x3f8239;
	d->texture = init_texture(d, path);
}
