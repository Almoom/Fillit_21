/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:18:39 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/27 13:18:39 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_struct(int **arr)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((arr[i][0] - arr[j][0]) == 0 && (arr[i][1] - arr[j][1]) == 1)
				count++;
			if ((arr[i][0] - arr[j][0]) == 1 && (arr[i][1] - arr[j][1]) == 0)
				count++;
		}
	}
	return ((count == 3 || count == 4) ? 0 : 1);
}

int		ft_max(int **tab, int flag)
{
	int		i;
	int		t;

	i = -1;
	t = 0;
	while (++i < 4)
		t < tab[i][flag] ? t = tab[i][flag] : 0;
	return (t);
}

int		ft_newline_valid(char *str)
{
	return (str[0] == '\0' ? 1 : 0);
}

int		ft_not_valid_sim(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (1);
		str++;
	}
	return (0);
}

int		ft_valid_line(char *str)
{
	return (ft_strlen(str) == 4 && !ft_not_valid_sim(str));
}
