/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:18:31 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/27 13:18:31 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(char *argv)
{
	int		fd;
	char	*l;
	char	**split;
	int		**arr[27];

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (ft_usage_file());
	if (!ft_get_next_file(fd, &l) || ft_check_file(ft_strlen(l))
	|| ft_not_valid_sim(l) || ft_not_newl_valid(l, ft_card_numb(ft_strlen(l))))
	{
		free(l);
		return (1);
	}
	if (ft_not_valid_card(split = ft_strsplit(l, '\n')))
	{
		free(l);
		return (1);
	}
	if (ft_valid(split, l, arr))
	{
		return (1);
	}
	if (close(fd) == -1)
		return (1);
	return (ft_find_min_square(arr));
}

int		ft_check_file(size_t n)
{
	if (n > 545)
		return (1);
	if (n > 419)
		return (n % 20 == n / 20 - 22 ? 0 : 1);
	return (n % 20 == n / 20 - 1 ? 0 : 1);
}

int		ft_card_numb(size_t n)
{
	return ((n + 1) / 21);
}

int		ft_not_newl_valid(char *s, int num)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if ((i + 1) % 21 == 0 && s[i] != '\n')
			return (1);
		i++;
	}
	while (*s)
	{
		if (*s == '\n')
			n++;
		s++;
	}
	return ((n != num * 5 - 1) ? 1 : 0);
}

int		ft_not_valid_card(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s[i]) != 4)
		{
			ft_free_mass_of_str(s);
			return (1);
		}
		i++;
	}
	return (0);
}
