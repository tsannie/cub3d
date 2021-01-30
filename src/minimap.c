/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:00:35 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 12:18:19 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_minimap(t_param *set)
{
	int		res;

	res = (set->res_x < set->res_y) ? set->res_x : set->res_y;
	set->resm_size = res / 2;
	set->start_size = res / 20;
	set->end_size = set->resm_size + set->start_size;
	if ((set->resm_size / set->size_map_x) < (set->resm_size / set->size_map_y))
		set->size_cub = (set->resm_size / set->size_map_x);
	else
		set->size_cub = (set->resm_size / set->size_map_y);
	set->s_x = set->start_size;
	set->s_y = set->start_size;
	set->e_x = set->size_cub + set->start_size;
	set->e_y = set->size_cub + set->start_size;
	set->i_line = -1;
}

void	print_player(t_param *set)
{
	int		*cord;

	print_square(set, cord = create_coord(set->pps_x - (set->size_cub / 6),
		set->pps_y - (set->size_cub / 6), set->ppe_x + (set->size_cub / 6),
		set->ppe_y + (set->size_cub / 6)), create_color(102, 102, 255));
	free(cord);
}

void	color_map(t_param *set, int a, int i, int e)
{
	int *res;

	res = NULL;
	if (set->map[i][e] == '1')
		print_square(set, res = create_coord(set->s_x, set->s_y,
			set->e_x, set->e_y), create_color(204, 0, 0));
	if (set->map[i][e] == '0')
		print_square(set, res = create_coord(set->s_x, set->s_y,
			set->e_x, set->e_y), create_color(0, 102, 0));
	if (set->map[i][e] == '2')
		print_square(set, res = create_coord(set->s_x, set->s_y,
			set->e_x, set->e_y), create_color(168, 26, 225));
	if (set->map[i][e] == set->pos)
	{
		print_square(set, res = create_coord(set->s_x, set->s_y,
			set->e_x, set->e_y), create_color(206, 188, 214));
		if (a == -1)
			save_pos(set);
	}
	set->s_x = set->s_x + set->size_cub;
	set->e_x = set->e_x + set->size_cub;
	free(res);
}

void	map_in_minimap(t_param *set, int a)
{
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
			color_map(set, a, i, e);
			e++;
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
}

int		minimap(t_param *set, int a)
{
	init_minimap(set);
	map_in_minimap(set, a);
	if (a != -2)
	{
		if (print_line(set) == -1)
			return (-1);
	}
	return (0);
}
