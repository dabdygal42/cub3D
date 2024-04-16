/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:34:47 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/16 14:28:54 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	add_rownode(t_g_assets *c, t_row_list *node)
{
	t_row_list	*tmp;

	if (c->rowlist == NULL)
		c->rowlist = node;
	else
	{
		tmp = c->rowlist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (1);
}

static int	init_map(t_g_assets *c)
{
	int	i;

	c->map = (int **) malloc(sizeof(int *) * (c->row_qty + 1));
	if (!c->map)
		return (-2 - write(STDERR_FILENO, "Error\n", 6));
	i = 0;
	while (i <= c->row_qty)
	{
		c->map[i] = NULL;
		i++;
	}
	i = 0;
	while (i < c->row_qty)
	{
		c->map[i] = (int *) malloc(sizeof(int) * (c->col_qty));
		if (!c->map)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	list_to_matrix(t_g_assets *c)
{
	int			i;
	int			j;
	t_row_list	*tmp;

	if (init_map(c) <= 0)
		return (-1);
	i = 0;
	tmp = c->rowlist;
	while (i < c->row_qty)
	{
		j = 0;
		while (j < c->col_qty)
		{
			if (j < tmp->size)
				c->map[i][j] = tmp->row[j];
			else
				c->map[i][j] = ' ';
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}
