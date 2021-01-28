/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:00:03 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 16:24:32 by tsannie          ###   ########.fr       */
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
	else if (argc == 3)
	{
		if (ft_streql(argv[2], "--save") == 1)
			printf("Lets go save");
	}
	return (0);
}
