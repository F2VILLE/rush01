/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:42:47 by regralin          #+#    #+#             */
/*   Updated: 2025/08/16 17:05:11 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_argv(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_error();
		return (1);
	}
	if (ft_strlen(av[1]) != 31)
	{
		ft_error();
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{

	if (!ft_check_argv(argc, argv))
		return (ft_error(), 0);

	return (0);
}
