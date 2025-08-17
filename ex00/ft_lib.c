/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:16:01 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/17 01:38:01 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_lib.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	println(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_digit(char c)
{
	return ((c >= '0') && (c <= '9'));
}
