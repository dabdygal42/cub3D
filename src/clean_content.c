/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:48:36 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/16 16:02:15 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	clean_content(t_g_assets *c)
{
	t_row_list	*tmp;
	t_row_list	*tmp2;
	int			i;

	ft_free((void *) &c->no);
	ft_free((void *) &c->so);
	ft_free((void *) &c->we);
	ft_free((void *) &c->ea);
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
