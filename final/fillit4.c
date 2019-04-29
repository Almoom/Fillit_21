/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:18:52 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/27 13:18:53 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid(char **split, char *line, int ***arr)
{
	int		n;
	int		i;
	char	*tab[5];

	n = 0;
	tab[4] = 0;
	while (n < ft_card_numb(ft_strlen(line)))
	{
		arr[n + 1] = NULL;
		i = -1;
		while (++i < 4)
			tab[i] = split[i + n * 4];
		arr[n] = ft_create_int_tab(6, 2);
		if (ft_check_struct(ft_make_tab(tab, arr[n])) || ft_tab_dop(arr[n], n))
		{
			ft_free_mass_of_str(split);
			free(line);
			ft_free_int_tab(arr);
			return (1);
		}
		n++;
	}
	free(line);
	ft_free_mass_of_str(split);
	return (0);
}

int		**ft_change_map(int **arr)
{
	int		i;
	int		min_x;
	int		min_y;

	i = -1;
	min_x = 4;
	min_y = 4;
	while (++i < 4)
	{
		if (min_x > arr[i][0])
			min_x = arr[i][0];
		if (min_y > arr[i][1])
			min_y = arr[i][1];
	}
	i = -1;
	while (++i < 4)
	{
		arr[i][0] = arr[i][0] - min_x;
		arr[i][1] = arr[i][1] - min_y;
	}
	return (arr);
}

int		ft_tab_dop(int **tab, int n)
{
	if (tab[4][1] != 0 || tab[4][0] != 0)
		return (1);
	tab[4][1] = 65 + n;
	tab[4][0] = 65 + n;
	tab[5][1] = ft_max(tab, 1);
	tab[5][0] = ft_max(tab, 0);
	return (0);
}

int		ft_count_of_kart(int ***arr)
{
	int		n;

	n = 0;
	while (arr[n] != NULL)
		n++;
	return (n);
}

int		ft_side_of_map(int nb)
{
	int i;

	i = 1;
	while ((nb - i * i) > 0)
		i++;
	return (i);
}
