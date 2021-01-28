/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:43:10 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 15:13:19 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	refresh_w(t_param *set)
{
	set->i = ((set->perso_x + ((set->dx * set->lgr)))
		- set->start_size) / set->size_cub;
	set->e = ((set->perso_y + ((set->dy * set->lgr)))
		- set->start_size) / set->size_cub;
}

void	first_search(t_param *set)
{
	int		check;

	check = 0;
	while (set->map[(int)set->e][(int)set->i] != '1'
		&& set->map[(int)set->e][(int)set->i] != ' '
		&& set->map[(int)set->e][(int)set->i] != '4'
		&& set->map[(int)set->e][(int)set->i] != '5')
	{
		if (set->map[(int)set->e][(int)set->i] == '6')
		{
			if (++check == 1)
				set->spr_pres++;
			set->sprite = 1;
		}
		if (set->map[(int)set->e][(int)set->i] == '2' && set->sprite == 0)
		{
			set->spr_pres = 0;
			set->sprite = 1;
			set->map[(int)set->e][(int)set->i] = '6';
			set->lgr_spr = set->lgr;
			set->xspe_spr = 0;
		}
		set->lgr += speed_moove(set);
		refresh_w(set);
	}
}

void	pres_search(t_param *set)
{
	set->lgr -= speed_moove(set);
	refresh_w(set);
	while (set->map[(int)set->e][(int)set->i] != '1'
		&& set->map[(int)set->e][(int)set->i] != ' '
		&& set->map[(int)set->e][(int)set->i] != '4'
		&& set->map[(int)set->e][(int)set->i] != '5')
	{
		set->lgr += speed_moove(set) / ((float)set->res_x / 20);
		refresh_w(set);
	}
	if (set->map[(int)set->e][(int)set->i] == '1')
	{
		set->xspe = 0;
		set->map[(int)set->e][(int)set->i] = '4';
	}
	else if (set->map[(int)set->e][(int)set->i] == ' ')
	{
		set->xspe = 0;
		set->map[(int)set->e][(int)set->i] = '5';
	}
}

float	search_wall(t_param *set)
{
	set->lgr = 0;
	set->dx = cos(set->angle);
	set->dy = sin(set->angle);
	refresh_w(set);
	first_search(set);
	pres_search(set);
	if (set->i_line == -1)
		align_text(set);
	if (set->sprite == 1)
		pres_sprite(set);
	return (set->lgr);
}

void	wash_map(t_param *set)
{
	int		i;
	int		e;

	i = 0;
	while (set->map[i])
	{
		e = 0;
		while (set->map[i][e])
		{
			if (set->map[i][e] == '4')
				set->map[i][e] = '1';
			if (set->map[i][e] == '5')
				set->map[i][e] = ' ';
			if (set->map[i][e] == '6')
				set->map[i][e] = '2';
			e++;
		}
		i++;
	}
}
