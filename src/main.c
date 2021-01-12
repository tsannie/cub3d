/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:00:03 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/12 18:21:17 by tsannie          ###   ########.fr       */
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
	set->size_map = 0;
}

int		main(int argc, char **argv)
{
	t_param	*set;

	if (argc == 2)
	{
		if (!(set = malloc(sizeof(t_param))))
			return (-1);
		init(set);
		if (param_trim(argv[1], set) == -1 || check_map(set) == -1)
			return (-1);
		print_struct(set);
		print_map(set);
		start_cub(set);
		free(set);
	}
	return (0);
}
