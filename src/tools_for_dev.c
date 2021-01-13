/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_dev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:21:10 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/13 12:18:43 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_struct(t_param *set)
{
	int		i;

	printf("res_x = |%d|\n", set->res_x);
	printf("res_y = |%d|\n", set->res_y);
	printf("text_no = |%s|\n", set->text_no);
	printf("text_so = |%s|\n", set->text_so);
	printf("text_we = |%s|\n", set->text_we);
	printf("text_ea = |%s|\n", set->text_ea);
	printf("text_s = |%s|\n", set->text_s);
	printf("f_r = |%d|\n", set->f_r);
	printf("f_g = |%d|\n", set->f_g);
	printf("f_b = |%d|\n", set->f_b);
	printf("c_r = |%d|\n", set->c_r);
	printf("c_g = |%d|\n", set->c_g);
	printf("c_b = |%d|\n", set->c_b);
	printf("size_map = %d\n", set->size_map_x);
	i = 0;
	printf("map : \n");
	while (set->map[i] && set->map)
	{
		printf("%s\n", set->map[i]);
		i++;
	}
}

void	print_map(t_param *set)
{
	int		i;
	int		e;

	i = 0;
	ft_putstr_fd("Map : \n", 1);
	while (set->map[i])
	{
		e = 0;
		while (set->map[i][e])
		{
			if (set->map[i][e] == ' ')
				ft_putchar_fd('-', 1);
			else
				ft_putchar_fd(set->map[i][e], 1);
			e++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}
