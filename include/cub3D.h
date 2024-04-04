/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:57:14 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/04 13:12:17 by dabdygal         ###   ########.fr       */
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

void		init(t_data *d);
void		render(t_data *d);

//hooks
int			close_window(void);
int			key_handler(int key, t_data *d);

//parsing
int			is_valid_sdf(int argc, char *argv[]);

#endif
