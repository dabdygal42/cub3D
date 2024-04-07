/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:08:31 by akeryan           #+#    #+#             */
/*   Updated: 2024/04/07 16:19:08 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_map(int **arr, int rows, int cols)
{
	int	a, b;

	a = -1;
	b = -1;
	while (++a < rows)	
	{
		while (++b < cols)
			printf("%d ", arr[a][b]);
		printf("\n");
		b = -1;
	}
}