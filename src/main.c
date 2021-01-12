/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:00:03 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/12 11:41:00 by tsannie          ###   ########.fr       */
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
		param_trim(argv[1], set);
	}
	free(set);
	return (0);
}
