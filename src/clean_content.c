/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:48:36 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/16 13:10:20 by dabdygal         ###   ########.fr       */
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
	while (i < c->row_qty)
	{
		ft_free((void *) c->map[i]);
		i++;
	}
}
