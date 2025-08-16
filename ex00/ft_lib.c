/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:16:01 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/17 00:22:29 by fdeville         ###   ########.fr       */
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
