/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeville <fdeville@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 23:30:14 by fdeville          #+#    #+#             */
/*   Updated: 2025/08/16 00:19:45 by fdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

char	*ft_strcat(char *s1, char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);	
}

void	print_usage(char *prog_name)
{
	char	*m1 = "Usage : ";
	char	*m2 =  " \"col1top col2top col3top col4top col1bottom col2bottom col3bottom col4bottom row1left row2left row3left row4left row1right row2right row3right row4right\"\n"; 
	char	msg[ft_strlen(m1) + ft_strlen(m2) + ft_strlen(prog_name) + 1];

	msg[0] = '\0';
	ft_strcat(msg, m1);
	ft_strcat(msg, prog_name);
	ft_strcat(msg, m2);
	write(1, msg, ft_strlen(msg));
}

typedef struct s_grid
{
	int	size;
	int	**matrix;
} t_grid;

int	is_digit(char c)
{
	return ((c >= '0' ) && (c <= '9'))
}

int	validate_grid_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (!is_digit(str[i++]))	
			return (0);
	return (1);
}
char	**split_str(char *str)
{
	char	**arr;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			arr[j][k] = '\0';
			k = 0;
			j++;
		}
		else {
			arr[j][k] = str[i];
			k++;
		}
		i++;
	}

	return (arr);
}

t_grid	create_grid_from_str(char *str, t_grid g)
{
	if (!validate_grid_str(str))
		return (0);

	g->matrix = malloc()
}

void	print_error(char *msg)
{
	char	hdr[16];
	
	hdr = "\033[94m[Error]\033[0m ";
	write(1, hdr, ft_strlen(hdr));
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	t_grid	grid;

	if (argc != 2)
	{
		print_usage(argv[0]);
	}

	char	*t = "this is a big big  te s     test   1   2 3";

	char	**arr = split_str(t);

	

	create_grid_from_str(argv[1], grid);
	if (!grid)
	{
		print_error("Invalid values for the board.");
	}

	return (0);
}
