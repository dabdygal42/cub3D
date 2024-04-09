/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:09:29 by dabdygal          #+#    #+#             */
/*   Updated: 2024/04/09 14:35:03 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

static int	check_open_warn(int argc, char *argv[])
{
	int	fd;
	int	i;

	if (argc != 2 || !argv || !argv[0] || !argv[1])
	{
		write(STDERR_FILENO, "Error\nNumber of arguments expected: 1\n", 38);
		return (-1);
	}
	i = 0;
	while (argv[1][i])
		i++;
	if (ft_strcmp(argv[1] + i - 4, ".cub") != 0)
	{
		write(STDERR_FILENO, "Error\nExtension expected: \".cub\"\n", 33);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(NULL);
		return (-1);
	}
	return (fd);
}

static int	parse_elements(int fd, t_g_assets *c)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (parse_line(str, c) <= 0)
		{
			free(str);
			return (0);
		}
		free(str);
		str = get_next_line(fd);
	}
	if (errno != 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(NULL);
		return (-1);
	}
	return (1);
}

int	parse(int argc, char *argv[], t_g_assets *content)
{
	int	fd;

	fd = check_open_warn(argc, argv);
	if (fd < 0)
		return (0);
	if (parse_elements(fd, content) <= 0)
		return (0);
	if (close(fd) < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(NULL);
		return (0);
	}
	return (1);
}
