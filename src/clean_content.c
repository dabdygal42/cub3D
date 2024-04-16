/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:48:36 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/16 20:26:14 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	clean_content(t_assets *c)
{
	t_row_list	*tmp;
	t_row_list	*tmp2;
	int			i;

	ft_free((void *) &c->tex_path[0]);
	ft_free((void *) &c->tex_path[1]);
	ft_free((void *) &c->tex_path[2]);
	ft_free((void *) &c->tex_path[3]);
	tmp = c->rowlist;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_free((void *) &tmp);
		tmp = tmp2;
	}
	i = 0;
	while (c->map && i < c->row_qty)
	{
		if (c->map[i])
			free(c->map[i]);
		i++;
	}
	if (c->map)
		free(c->map);
}
