/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:02:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/26 22:21:25 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	col_up(t_param *set)
{
	int		e;
	int		i;
	int		g;
	int		p;

	g = (set->pps_x + (set->ppe_x - set->pps_x) - set->start_size)
		/ set->size_cub;
	p = (set->pps_y + (set->ppe_x - set->pps_x) - set->start_size)
		/ set->size_cub;
	i = (set->pps_y - set->start_size) / set->size_cub;
	e = (set->pps_x - set->start_size) / set->size_cub;
	if (set->map[i][e] == '1' || set->map[i][g] == '1'
		|| set->map[p][g] == '1' || set->map[p][e] == '1'
		|| set->map[i][e] == '2' || set->map[i][g] == '2'
		|| set->map[p][g] == '2' || set->map[p][e] == '2')
	{
		set->pps_y = set->pps_y - (sin(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y - (sin(set->orient_p) * speed_moove(set));
		set->pps_x = set->pps_x - (cos(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x - (cos(set->orient_p) * speed_moove(set));
	}
}

void	col_down(t_param *set)
{
	int		e;
	int		i;
	int		g;
	int		p;

	g = (set->ppe_x - (set->ppe_x - set->pps_x) - set->start_size)
		/ set->size_cub;
	p = (set->ppe_y - (set->ppe_x - set->pps_x) - set->start_size)
		/ set->size_cub;
	i = (set->ppe_y - set->start_size) / set->size_cub;
	e = (set->ppe_x - set->start_size) / set->size_cub;
	if (set->map[i][e] == '1' || set->map[i][g] == '1'
		|| set->map[p][g] == '1' || set->map[p][e] == '1'
		|| set->map[i][e] == '2' || set->map[i][g] == '2'
		|| set->map[p][g] == '2' || set->map[p][e] == '2')
	{
		set->pps_y = set->pps_y + (sin(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y + (sin(set->orient_p) * speed_moove(set));
		set->pps_x = set->pps_x + (cos(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x + (cos(set->orient_p) * speed_moove(set));
	}
}

void	col_left(t_param *set)
{
	int		e;
	int		i;
	int		g;
	int		p;

	g = (set->pps_y + (set->ppe_x - set->pps_x) - set->start_size)
		/ set->size_cub;
	p = (set->pps_x + (set->ppe_x - set->pps_x) - set->start_size)
		/ set->size_cub;
	i = (set->pps_y - set->start_size) / set->size_cub;
	e = (set->pps_x - set->start_size) / set->size_cub;
	if (set->map[i][e] == '1' || set->map[g][e] == '1'
		|| set->map[g][p] == '1' || set->map[i][p] == '1'
		|| set->map[i][e] == '2' || set->map[g][e] == '2'
		|| set->map[g][p] == '2' || set->map[i][p] == '2')
	{
		set->pps_x = set->pps_x - (sin(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x - (sin(set->orient_p) * speed_moove(set));
		set->pps_y = set->pps_y + (cos(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y + (cos(set->orient_p) * speed_moove(set));
	}
}

void	col_right(t_param *set)
{
	int		e;
	int		i;
	int		g;
	int		p;

	g = (set->ppe_y - (set->ppe_x - set->pps_x) - set->start_size)
		/ set->size_cub;
	p = (set->ppe_x - (set->ppe_x - set->pps_x) - set->start_size)
		/ set->size_cub;
	i = (set->ppe_y - set->start_size) / set->size_cub;
	e = (set->ppe_x - set->start_size) / set->size_cub;
	if (set->map[i][e] == '1' || set->map[g][e] == '1'
		|| set->map[g][p] == '1' || set->map[i][p] == '1'
		|| set->map[i][e] == '2' || set->map[g][e] == '2'
		|| set->map[g][p] == '2' || set->map[i][p] == '2')
	{
		set->pps_x = set->pps_x + (sin(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x + (sin(set->orient_p) * speed_moove(set));
		set->pps_y = set->pps_y - (cos(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y - (cos(set->orient_p) * speed_moove(set));
	}
}

void	colision(t_param *set, int a)
{
	if (a == 1)
		col_up(set);
	if (a == 2)
		col_down(set);
	if (a == 3)
		col_left(set);
	if (a == 4)
		col_right(set);
}
