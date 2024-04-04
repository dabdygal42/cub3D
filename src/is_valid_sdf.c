/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_sdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:09:29 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/04 13:51:40 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	is_valid_input(int argc, char *argv[])
{
	if (argc != 2 || !argv || !argv[0] || !argv[1])
	{
		write(STDERR_FILENO, "Error\nNumber of arguments expected: 1\n", 38);
		return (0);
	}
	argv++;
	while (**argv)
		(*argv)++;
	(*argv) -= 4;
	if (ft_strcmp(*argv, ".cub") != 0)
	{
		write(STDERR_FILENO, "Error\nExtension expected: \".cub\"\n", 33);
		return (0);
	}
	return (1);
}

//Check if scene description file is valid
int	is_valid_sdf(int argc, char *argv[])
{
	if (is_valid_input(argc, argv) <= 0)
		return (0);
	return (1);
}
