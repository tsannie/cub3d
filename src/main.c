/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:00:03 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 12:09:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init(t_param *set)
{
	set->res_x = -1;
	set->res_y = -1;
	set->f_b = -1;
	set->f_r = -1;
	set->f_g = -1;
	set->size_map_x = 0;
	if (set->save != 1)
		set->save = 0;
}

void	free_struct(t_param *set)
{
	int i;

	if (set->text_no)
		free(set->text_no);
	if (set->text_so)
		free(set->text_so);
	if (set->text_we)
		free(set->text_we);
	if (set->text_ea)
		free(set->text_ea);
	if (set->text_s)
		free(set->text_s);
	i = -1;
	if (set->map)
	{
		while (set->map[++i])
			free(set->map[i]);
		free(set->map);
	}
	if (set->cpy)
		free(set->cpy);
	if (set)
		free(set);
}

int		save(int argc, char **argv, t_param *set)
{
	if (argc == 3)
	{
		if (ft_streql(argv[2], "--save") == 1)
			set->save = 1;
		else
		{
			free_struct(set);
			ft_putstr_fd("Error\nArgument inconnu.\n", 1);
			return (-1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	*set;

	if (argc == 2 || argc == 3)
	{
		if (!(set = malloc(sizeof(t_param))))
			return (error_param(2));
		if (save(argc, argv, set) == -1)
			return (-1);
		init(set);
		if (param_trim(argv[1], set) == -1 || check_map(set) == -1)
		{
			free_struct(set);
			return (-1);
		}
		start_cub(set);
		free_struct(set);
	}
	return (0);
}
