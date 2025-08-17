/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:06:25 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/17 02:20:21 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "args.h"
#include "grid.h"
#include "ft_lib.h"

int	main(int argc, char *argv[])
{
	t_grid	grid;
	int	*clues;
	int	clues_count;

	if (argc != 2 || !validate_args(argv[1]))
	{
		println("Usage : ./rush01 \"<coltop4-9> <colbot4-9> <rowleft4-9> <rowright4-9>\"\n");
		return (1);
	}
	clues_count = 0;
	clues = clues_from_str(argv[1], &clues_count);
	create_grid(clues, &grid, clues_count);
	display_grid(grid);
	return (0);
}
