/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:00:13 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/17 18:49:07 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "args.h"
#include "ft_lib.h"
#include <stdio.h>

int	validate_args(char *str)
{
	int	i;
	int	ccount;

	i = 0;
	ccount = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] == ' ')
			{
				printf("Char %c (%d) is not supposed to be a space !\n", str[i], i);
				return (0);
			}
			else if (!is_digit(str[i]))
			{
				printf("%c is not a digit \n", str[i]);
				return (0);
			}
			else if (is_digit(str[i]))
				ccount++;
		}
	}
	if (ccount % 4 != 0)
		return (0);
	if (ccount / 4 < 4 || ccount / 4 > 9)
		return (0);
	return (1);
}
