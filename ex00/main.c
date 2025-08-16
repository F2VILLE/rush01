/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:06:25 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/17 00:22:54 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "args.h"
#include "grid.h"
#include "ft_lib.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		println("Usage : ./rush01 \"<coltop4-9> <colbot4-9> <rowleft4-9> <rowright4-9>\"\n");
		return (1);
	}
	println(argv[1]);
	return (0);
}
