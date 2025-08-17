/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:00:44 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/17 02:21:32 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "grid.h"
#include "ft_lib.h"
#include <stdlib.h>

t_grid	create_grid(int *clues, t_grid *grid, int size)
{
	int	i;
	int	j;

	grid->size = size;
	grid->clues = clues;
	grid->matrix = malloc(size * sizeof(int*));
	i = 0;
	j = 0;
	while (j < size)
	{
		grid->matrix[j] = malloc(size * sizeof(int));
		i = 0;
		while (i < size)
		{
			grid->matrix[j][i] = 0;
			i++;
		}
		j++;
	}
	return (*grid);
}

int	*clues_from_str(char *str, int *clues_count)
{
	int	*clues;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			(*clues_count)++;
		i++;
	}
	clues = malloc((*clues_count) * sizeof(int));
	i = 0;
	while (str[i] != '\0')
	{
		if (is_digit(str[i]))
			clues[j++] = str[i] - '0';
		i++;
	}
	return (clues);
}

void display_grid(t_grid grid)
{
	int	y;
	int	x;
	int	ci;

	ci = 0;
	y = 0;
	x = 0;
	while (ci < grid.size)
		ft_putchar(grid.clues[ci++]);
	ci += grid.size;
	while (y < grid.size)
	{
		x = 0;
		while (x < grid.size)
		{
			ft_putchar(grid.clues[ci]);
			ft_putchar(grid.matrix[y][x]);
			ft_putchar(grid.clues[ci + grid.size]);
			ci++;
			x++;
		}
		y++;
	}
	ci = 0;
	while (ci < grid.size)
		ft_putchar(grid.clues[(ci++) + grid.size]);
}
