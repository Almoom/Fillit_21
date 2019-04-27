/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 09:49:08 by ljalikak          #+#    #+#             */
/*   Updated: 2019/03/04 13:34:25 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_usage_file());
	else if (ft_fillit(argv[1]) == 1)
		ft_putstr("error\n");
	return (0);
}

void	ft_print_map(char **str)
{
	int		n;

	n = 0;
	while (str[n])
	{
		ft_putstr(str[n]);
		ft_putchar('\n');
		n++;
	}
}

int		ft_check_cross(char **map, int **arr, int i, int j)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		if (map[i + arr[n][1]][j + arr[n][0]] != '.')
			return (1);
		n++;
	}
	return (0);
}

void	ft_add_kart_in_map(char **map, int **arr, int i, int j)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		map[i + arr[n][1]][j + arr[n][0]] = arr[4][0];
		n++;
	}
}

void	ft_remove_kart_from_map(char **map, int **arr, int i, int j)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		map[i + arr[n][1]][j + arr[n][0]] = '.';
		n++;
	}
}
