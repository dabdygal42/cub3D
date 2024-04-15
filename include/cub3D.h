/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:57:14 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/15 17:44:47 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# define WINDOW_WIDTH	1600
# define WINDOW_HEIGHT	1200

# define ESC		53
# define KEY_7		89	
# define KEY_8		91
# define KEY_UP		13
# define KEY_DOWN	1
# define KEY_LEFT	0
# define KEY_RIGHT	2

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		pix_bits;
	int		l_bytes;
	int		endi;
	void	*img;
	char	*buf;
	int		buf_size;
	int		width;
	int		height;
}	t_data;

typedef struct s_row_list
{
	int					*row;
	int					size;
	struct s_row_list	*next;
}	t_row_list;

typedef struct s_game_assets
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor_rgb[3];
	int			ceil_rgb[3];
	int			**map;
	t_row_list	*rowlist;
	int			row_qty;
	int			col_qty;
}	t_g_assets;

void		init(t_data *d);
void		render(t_data *d);

//hooks
int			close_window(void);
int			key_handler(int key, t_data *d);

//parsing
int			parse(int argc, char *argv[], t_g_assets *content);
int			assign_rgb(int *rgb, char *str);
int			add_mapline(char *str, t_g_assets *c, int done);
int			add_rownode(t_g_assets *c, t_row_list *node);
void		clean_content(t_g_assets *c);

#endif
