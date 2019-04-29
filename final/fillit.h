/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:55:42 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/23 17:55:44 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

int		ft_find_min_square(int ***arr);
int		ft_count_of_kart(int ***arr);
int		ft_side_of_map(int nb);
char	**ft_create_char_table(int i, int j);
int		**ft_create_int_tab(int i, int j);
void	ft_free_mass_of_str(char **str);
int		ft_place_kart_in_map(char **map, int ***arr, int len, int k);
int		ft_find_place_for_kart(char **map, int ***arr, int len, int k);
int		ft_check_cross(char **map, int **arr, int i, int j);
void	ft_add_kart_in_map(char **map, int **arr, int i, int j);
void	ft_remove_kart_from_map(char **map, int **arr, int i, int j);
void	ft_print_map(char **str);
int		ft_fillit(char *argv);
int		ft_valid(char **split, char *line, int ***arr);
int		ft_free_int_tab(int ***arr);
int		ft_tab_dop(int **tab, int n);
int		**ft_make_tab(char **s, int **t);
int		ft_not_valid_card(char **s);
int		ft_not_newl_valid(char *s, int num);
int		ft_card_numb(size_t n);
int		ft_check_file(size_t n);
int		ft_valid_line(char *str);
int		ft_not_valid_sim(char *str);
int		ft_newline_valid(char *str);
int		ft_max(int **tab, int flag);
int		ft_check_struct(int **arr);
int		**ft_change_map(int **arr);
int		ft_usage_file(void);
#endif
