/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:00:35 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/13 18:46:51 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_minimap(t_param *set)
{
	int		res;

	res = (set->res_x < set->res_y) ? set->res_x : set->res_y;
	set->resm_x = res / 2;
	set->resm_y = res / 2;
	set->start_x = res / 60;
	set->start_y = res / 60;
	set->end_x = set->resm_x + set->start_x;
	set->end_y = set->resm_y + set->start_y;
	if ((set->resm_x / set->size_map_x) < (set->resm_y / set->size_map_y))
		set->size_cub = (set->resm_x / set->size_map_x);
	else
		set->size_cub = (set->resm_y / set->size_map_y);
	set->s_x = set->start_x;
	set->s_y = set->start_y;
	set->e_x = set->size_cub + set->start_x;
	set->e_y = set->size_cub + set->start_y;
}

void	save_pos(t_param *set)
{
	int		cord[4];
	int		a;

	a = set->size_cub / 3;
	set->pps_x = set->s_x + (a);
	set->pps_y = set->s_y + (a);
	set->ppe_x = set->e_x - (a);
	set->ppe_y = set->e_y - (a);
	print_square(set, create_coord(cord, set->pps_x, set->pps_y,
		set->ppe_x, set->ppe_y), create_color(0, 11, 13, 12));
}

void	map_in_minimap(t_param *set, int a)
{
	int		cord[4];
	int		i;
	int		e;

	i = 0;
	while (set->map[i])
	{
		set->s_x = set->start_x;
		set->e_x = set->size_cub + set->start_x;
		e = 0;
		while (set->map[i][e])
		{
			if (set->map[i][e] == '1')
				print_square(set, create_coord(cord, set->s_x, set->s_y,
					set->e_x, set->e_y), create_color(0, 225, 159, 26));
			if (set->map[i][e] == '0')
				print_square(set, create_coord(cord, set->s_x, set->s_y,
					set->e_x, set->e_y), create_color(0, 225, 26, 65));
			if (set->map[i][e] == '2')
				print_square(set, create_coord(cord, set->s_x, set->s_y,
					set->e_x, set->e_y), create_color(0, 168, 26, 225));
			if (set->map[i][e] == set->pos)
			{
				print_square(set, create_coord(cord, set->s_x, set->s_y,
					set->e_x, set->e_y), create_color(0, 206, 188, 214));
				if (a == 0)
					save_pos(set);
			}
			e++;
			set->s_x = set->s_x + set->size_cub;
			set->e_x = set->e_x + set->size_cub;
		}
		set->s_y = set->s_y + set->size_cub;
		set->e_y = set->s_y + set->size_cub;
		i++;
	}
	if (a != 0)
		change_pos(set, a);
}

void	print_minimap(t_param *set, int a)
{
	int			cord[4];

	printf("regen map a = |%d| [...]\n", a);
	init_minimap(set);
	print_square(set, create_coord(cord, set->start_x, set->start_y,
		set->end_x, set->end_y), create_color(0, 255, 255, 255));
	map_in_minimap(set, a);
}
