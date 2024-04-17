/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:20:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/17 12:13:03 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static int	**map_init(void)
//{
	//int	**outmap;	
	//int	i;

	//int map[MAP_HEIGHT][MAP_WIDTH]=
	//{
		//{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		//{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
		//{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		//{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		//{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
		//{1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
		//{1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1},
		//{1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
		//{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		//{1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
		//{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1},
		//{1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		//{1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		//{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		//{1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		//{1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		//{1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
		//{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1},
		//{1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
		//{1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
		//{1,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
		//{1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,1},
		//{1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
		//{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	//};	
	//outmap = (int **)malloc(MAP_HEIGHT * sizeof(int *));
	//if (outmap == NULL)
	//{
		//printf("malloc failed in map_init\n");
		//free (outmap);
		//return (NULL);
	//}
	//i = -1;
	//while (++i < MAP_HEIGHT)
	//{
		//outmap[i] = (int *)malloc(MAP_WIDTH * sizeof(int));
		//if (outmap[i] == NULL)
		//{
			//printf("malloc failed in map_init\n");
			//while (--i > 0)
				//free(outmap[i]);
			//free(outmap);
			//return (NULL);
		//}
		//ft_memcpy(outmap[i], map[i], sizeof(map[i]));
	//}
	//return (outmap);
//}

t_texture	**init_texture(t_data *d, t_assets *content)
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
		tex[i]->path = content->tex_path[i];
		tex[i]->img = mlx_xpm_file_to_image(d->mlx, tex[i]->path, \
			&tex[i]->width, &tex[i]->height);
		tex[i]->buf = mlx_get_data_addr(tex[i]->img, &tex[i]->pix_bits, \
			&tex[i]->l_bytes, &tex[i]->endi);
	}
	return (tex);
}

void	init_content(t_assets *content)
{
	content->tex_path = (char **)malloc(sizeof(char *) * 4);
	content->tex_path[0] = NULL;
	content->tex_path[1] = NULL;
	content->tex_path[2] = NULL;
	content->tex_path[3] = NULL;
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

void	init(t_data *d, t_assets *content)
{
	d->assets = content;
	d->map_width = content->col_qty;
	d->map_heigth = content->row_qty;
	d->screen_height = SCREEN_HEIGHT;
	d->screen_width = SCREEN_WIDTH;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, SCREEN_WIDTH, d->screen_height, "CUB3D");
	d->img = NULL;
	d->world_map = content->map;
	d->pos_x = 22.0;
	d->pos_y = 11.5;
	d->dir_x = -1.0;
	d->dir_y = 0.0;
	d->plane_x = 0.0;
	d->plane_y = 0.66;
	d->time = get_time();
	d->old_time = 0.0;
	d->view_shift = 0;
	d->ceiling_color = 0x6fecf7;
	d->floor_color = 0x3f8239;
	d->texture = init_texture(d, content);
}
