/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:20:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/17 20:12:02 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		tex[i]->img = mlx_xpm_file_to_image(d->mlx, tex[i]->path, &tex[i]->width, &tex[i]->height);
		if (tex[i]->img == NULL)
			printf ("ERROR: tex[i]->img is NULL\n");
		tex[i]->buf = mlx_get_data_addr(tex[i]->img, &tex[i]->pix_bits, \
			&tex[i]->l_bytes, &tex[i]->endi);
	}
	return (tex);
}

static void	init_player_position(t_data *d)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (++i < d->map_heigth - 1)
	{
		j = 0;
		while (++j < d->map_width - 1)
		{
			l = d->world_map[i][j];
			if (l == 'N' || l == 'E' || l == 'S' || l == 'W')
			{
				d->pos_x = i;
				d->pos_y = j;
				return ;
			}
		}
	}
}

static void	init_player_orientation(t_data *d)
{
	char	c;

	c = d->world_map[(int)d->pos_x][(int)d->pos_y];
	if ( c == 'N')
	{
		d->dir_x = -1.0;
		d->dir_y = 0.0;
	}
	else if (c == 'E')
		rotate_right(d, M_PI_2);
	else if (c == 'S')
		rotate_right(d, M_PI);
	else if (c == 'W')
		rotate_right(d, 3 * M_PI_2);
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

void	init(t_data *d, t_assets *c)
{
	d->assets = c;
	d->map_width = c->col_qty;
	d->map_heigth = c->row_qty;
	d->screen_height = SCREEN_HEIGHT;
	d->screen_width = SCREEN_WIDTH;
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		printf("ERROR: d->mlx is NULL\n");
	d->win = mlx_new_window(d->mlx, SCREEN_WIDTH, d->screen_height, "CUB3D");
	if (d->win == NULL)
		printf("ERROR: d->win is NULL\n");
	d->img = NULL;
	d->world_map = c->map;
	init_player_position(d);
	d->dir_x = -1.0;
	d->dir_y = 0.0;
	d->plane_x = 0.0;
	d->plane_y = 0.66;
	init_player_orientation(d);
	d->ceiling_color = get_hex_from_rgb(c->ceil_rgb[0], c->ceil_rgb[1], c->ceil_rgb[2]);
	d->floor_color = get_hex_from_rgb(c->floor_rgb[0], c->floor_rgb[1], c->floor_rgb[2]);
	d->time = get_time();
	d->old_time = 0.0;
	d->view_shift = 0;
	d->texture = init_texture(d, c);
}
