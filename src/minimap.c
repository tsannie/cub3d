/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:00:35 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/18 16:04:43 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_minimap(t_param *set)
{
	int		res;

	res = (set->res_x < set->res_y) ? set->res_x : set->res_y;
	set->resm_size = res / 1.2;
	set->start_size = res / 60;
	set->end_size = set->resm_size + set->start_size;
	if ((set->resm_size / set->size_map_x) < (set->resm_size / set->size_map_y))
		set->size_cub = (set->resm_size / set->size_map_x);
	else
		set->size_cub = (set->resm_size / set->size_map_y);
	set->s_x = set->start_size;
	set->s_y = set->start_size;
	set->e_x = set->size_cub + set->start_size;
	set->e_y = set->size_cub + set->start_size;


}

void	save_pos(t_param *set, int a)
{
	int		size;

	size = set->size_cub / 3;
	set->pps_x = set->s_x + (size);
	set->pps_y = set->s_y + (size);
	set->ppe_x = set->e_x - (size);
	set->ppe_y = set->e_y - (size);
}

void	print_player(t_param *set)
{
	int		*cord;

	print_square(set, cord = create_coord(set->pps_x, set->pps_y,
		set->ppe_x, set->ppe_y), create_color(0, 11, 13, 12));
	free(cord);
}

void	map_in_minimap(t_param *set, int a)
{
	int		*cord;
	int		i;
	int		e;

	i = 0;
	while (set->map[i])
	{
		set->s_x = set->start_size;
		set->e_x = set->size_cub + set->start_size;
		e = 0;
		while (set->map[i][e])
		{
			if (set->map[i][e] == '1')
				print_square(set, cord = create_coord(set->s_x, set->s_y,
					set->e_x, set->e_y), create_color(0, 225, 159, 26));
			if (set->map[i][e] == '0')
				print_square(set, cord = create_coord(set->s_x, set->s_y,
					set->e_x, set->e_y), create_color(0, 225, 26, 65));
			if (set->map[i][e] == '2')
				print_square(set, cord = create_coord(set->s_x, set->s_y,
					set->e_x, set->e_y), create_color(0, 168, 26, 225));
			if (set->map[i][e] == set->pos)
			{
				print_square(set, cord = create_coord(set->s_x, set->s_y,
					set->e_x, set->e_y), create_color(0, 206, 188, 214));
				if (a == -1)
					save_pos(set, a);
			}
			e++;
			set->s_x = set->s_x + set->size_cub;
			set->e_x = set->e_x + set->size_cub;
		}
		set->s_y = set->s_y + set->size_cub;
		set->e_y = set->s_y + set->size_cub;
		i++;
	}
	if (a <= 0)
	print_player(set);
	if (a > 0)
		colision(set, a);
	middle_point(set);
	free(cord);
}

void	minimap(t_param *set, int a)
{
	int			*cord;

	//printf("regen map a = |%d| [...]\n", a);
	init_minimap(set);
	print_square(set, cord = create_coord(set->start_size, set->start_size,
		set->end_size, set->end_size), create_color(0, 255, 255, 255));
	map_in_minimap(set, a);
	print_line(set);
	free(cord);
}
