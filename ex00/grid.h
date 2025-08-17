/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 23:46:49 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/17 18:30:45 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GRID_H
# define GRID_H

typedef struct s_grid
{
	int	size;
	int	*clues;
	int	**matrix;
}	t_grid;

int	*clues_from_str(char *str, int *clues_count);
t_grid	create_grid(int *clues, t_grid *grid, int size);
void	display_grid(t_grid grid);

int	validate_grid(t_grid grid);

#endif
