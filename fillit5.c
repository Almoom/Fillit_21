/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:19:12 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/27 13:19:13 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_min_square(int ***arr)
{
	int		summ;
	int		len;
	char	**map;
	int		k;

	k = 0;
	summ = 4 * ft_count_of_kart(arr);
	len = ft_side_of_map(summ);
	map = ft_create_char_table(len, len);
	while (ft_place_kart_in_map(map, arr, len, 0) == 0)
	{
		len++;
		ft_free_mass_of_str(map);
		map = ft_create_char_table(len, len);
	}
	ft_print_map(map);
	ft_free_mass_of_str(map);
	ft_free_int_tab(arr);
	return (0);
}

int		ft_place_kart_in_map(char **map, int ***arr, int len, int k)
{
	if (arr[k] == 0)
		return (1);
	if (ft_find_place_for_kart(map, arr, len, k) == 1)
		return (1);
	else
		return (0);
}

int		ft_find_place_for_kart(char **map, int ***arr, int len, int k)
{
	int i;
	int j;

	i = 0;
	while (i < len - arr[k][5][1])
	{
		j = 0;
		while (j < len - arr[k][5][0])
		{
			if (ft_check_cross(map, arr[k], i, j) == 0)
			{
				ft_add_kart_in_map(map, arr[k], i, j);
				if (ft_place_kart_in_map(map, arr, len, k + 1) == 1)
					return (1);
				else
					ft_remove_kart_from_map(map, arr[k], i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
