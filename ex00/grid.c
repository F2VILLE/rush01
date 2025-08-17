/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:00:44 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/17 20:05:47 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "grid.h"
#include "ft_lib.h"
#include <stdlib.h>
#include <unistd.h>

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

	y = 0;
	x = 0;
	while (y < grid.size)
	{
		x = 0;
		while (x < grid.size)
		{
			ft_putchar('0' + grid.matrix[y][x]);
			if (x < grid.size - 1)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int	validate_line(int *line, int size)
{
	int	*sorted;
	int	i;

	sorted = ft_sort(line, size);
	while (i < size)
	{
		if (sorted[i] != i + 1)
			return (0);
	}
	return (1);
}

int	cast_clue(int *line, int size, int go_left)
{
	int	visibles;
	int	i;

	visibles = 0;
	i = 0;
	if (!go_left)
	{
		while (i < size - 1)
		{
			if (line[i] < line[i + 1])
				visibles++;
		}
	}
	else {
		i = size - 1;
		while (i > 0)
		{
			if (line[i] < line[i - 1])
				visibles++;
		}
	}
	return (visibles);
}

int	validate_pov(int *line, int size, int lclue, int rclue)
{
	if (cast_clue(line, size, 0) != lclue)
		return (0);
	if (cast_clue(line, size, 1) != rclue)
		return (0);
	return (1);
}

int	validate_grid(t_grid grid)
{
	int	y;
	int	x;
	int	z;
	int	row[grid.size];
	int	col[grid.size];

	y = 0;
	x = 0;
	z = 0;
	while (y < grid.size)
	{
		x = 0;
		while (x < grid.size)
		{
			int[y][x] == grid.matrix[y][x];
			if (y == 0)
			{
				z = 0;
				while (z < grid.size)
				{
					col[z] = grid[z][x];
				}
				if (!validate_line(col, grid.size))
					return (0);
				if (!validate_pov(col, grid.size, grid.clues[x], grid.clues[x + grid.size]))
					return (0);
			}
		}
		if (!validate_line(row, grid.size))
			return (0);
		if (!validate_pov(row, grid.size, grid.clues[2 * grid.size + y], grid.clues[3 * grid.size + y]))
			return (0);
		y++;
	}
	return (1);
}
