/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 09:49:08 by ljalikak          #+#    #+#             */
/*   Updated: 2019/03/04 13:34:25 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		**ft_create_int_table(int i, int j)
{
	int		n;
	int		**tab;

	n = 0;
	if ((tab = (int**)malloc(sizeof(tab) * i)) == NULL)
		return (0);
	while (n < i)
	{
		if ((tab[n] = (int*)malloc(sizeof(tab) * j)) == NULL)
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

// int		main()
// {
// 	int		**arr[26];
// 	int n = 4;
// 	int k = 2;
// 	int i = 0;
// 	int j = 0;
// 	int m = 1;
//
// 	arr[0] = ft_create_int_table(n, k);
// 	arr[1] = ft_create_int_table(n, k);
// 	while(i < n)
// 	{
// 		j = 0;
// 		while(j < k)
// 		{
// 			arr[0][i][j] = j + 1;
// 			arr[1][i][j] = j + 2;
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while(i < n)
// 	{
// 		printf("%d___%d\n",arr[0][i][0],arr[0][i][1]);
// 		i++;
// 	}
// 	printf("%s\n","________________");
// 	i = 0;
// 	while(i < n)
// 	{
// 		printf("%d___%d\n",arr[1][i][0],arr[1][i][1]);
// 		i++;
// 	}
//
// 	return (0);
// }

int		n_valid(char **str)
{
	return (*str[0] == '\n' ? 1 : 0);
}

int		not_valid_sim(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#')
			return (1);
		str++;
	}
	return (0);
}

int		valid(char *str, int **tab, int *i)
{
	int j;

	j = 0;
//printf("%d\n", valid_sim(str));
	if (ft_strlen(str) != 4 || not_valid_sim(str))
		return (0);

	printf("%s\n", str);
	while (str[j])
	{

		if (str[j] == '#')
		{
			tab[*i][1] = *i;
			tab[*i][0] = j;

		}
		j++;
	}

	(*i)++;

	return (1);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			flag;
	int			**arr[26];
	int			n;
	int			i;
	int			k;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (1);
	flag = 1;
	n = 0;
	i = 0;
	argc = 0;
	while (flag)
	{
		arr[n] = ft_create_int_table(6, 2);
		get_next_line(fd, &line) == 1 ? flag = valid(line, arr[n], &i) : printf("%s\n", "error");
		get_next_line(fd, &line) == 1 ? flag = valid(line, arr[n], &i) : printf("%s\n", "error");
		get_next_line(fd, &line) == 1 ? flag = valid(line, arr[n], &i) : printf("%s\n", "error");
		get_next_line(fd, &line) == 1 ? flag = valid(line, arr[n], &i) : printf("%s\n", "error");
		if (get_next_line(fd, &line))
			flag = n_valid(&line);
		else
			break ;
		n++;
	}
	if (close(fd) == -1)
		return (1);


	k = 0;
	while(k < 5)
	{
		printf("%d___%d\n",arr[0][k][0],arr[0][k][1]);
		k++;
	}


	return (0);
}
