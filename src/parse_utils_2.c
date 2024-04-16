/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:18:50 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/16 16:26:08 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <stdio.h>

int	additional_check(t_g_assets *c)
{
	if (c->row_qty == 0)
	{
		write(STDERR_FILENO, "Error\nNo map\n", 13);
		return (0);
	}
	if (check_char(0, 1) != 1)
	{
		write(STDERR_FILENO, "Error\nNo player\n", 16);
		return (0);
	}
	return (1);
}
