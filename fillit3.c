/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:18:45 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/27 13:18:46 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_create_int_tab(int i, int j)
{
	int		n;
	int		**tab;

	n = 0;
	if ((tab = (int**)ft_memalloc(sizeof(tab) * i)) == NULL)
		return (0);
	while (n < i)
	{
		if ((tab[n] = (int*)ft_memalloc(sizeof(tab) * j)) == NULL)
		{
			while (n > 0)
			{
				free(tab[n - 1]);
				n--;
			}
			free(tab);
			return (0);
		}
		n++;
	}
	return (tab);
}

char	**ft_create_char_table(int i, int j)
{
	int		n;
	char	**str;

	n = 0;
	if ((str = (char**)ft_memalloc(sizeof(str) * (i + 1))) == NULL)
		return (0);
	while (n < i)
	{
		if ((str[n] = ft_strnew(j)) == NULL)
		{
			while (n > 0)
			{
				free(str[n - 1]);
				n--;
			}
			free(str);
			return (0);
		}
		str[n] = ft_memset(str[n], '.', j);
		n++;
	}
	return (str);
}

int		**ft_make_tab(char **s, int **t)
{
	int i;
	int j;
	int k;

	i = -1;
	k = -1;
	if (s == NULL)
		return (NULL);
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == '#' && k < 5)
			{
				t[++k][1] = i;
				t[k][0] = j;
			}
		}
	}
	return (ft_change_map(t));
}

int		ft_free_int_tab(int ***arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (j < 6)
		{
			free(arr[i][j]);
			j++;
		}
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	return (1);
}

void	ft_free_mass_of_str(char **str)
{
	int		n;

	n = 0;
	while (str[n])
	{
		free(str[n]);
		n++;
	}
	free(str);
}
