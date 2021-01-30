/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:12:21 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 15:17:02 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	refresh_pw(t_param *set, int a, float dx, float dy)
{
	if (a == 1)
	{
		return (((set->perso_x + ((dx * set->pre_wall)))
			- set->start_size) / set->size_cub);
	}
	if (a == 2)
	{
		return (((set->perso_y + ((dy * set->pre_wall)))
			- set->start_size) / set->size_cub);
	}
	return (0);
}

int		pre_wall(t_param *set, float dx, float dy)
{
	float	i;
	float	e;

	i = refresh_pw(set, 1, dx, dy);
	e = refresh_pw(set, 2, dx, dy);
	while (set->map[(int)e][(int)i] != '4' && set->map[(int)e][(int)i] != '5'
		&& set->map[(int)e][(int)i] != '1' && set->map[(int)e][(int)i] != ' ')
	{
		set->pre_wall += speed_moove(set);
		i = refresh_pw(set, 1, dx, dy);
		e = refresh_pw(set, 2, dx, dy);
	}
	set->pre_wall -= speed_moove(set);
	i = refresh_pw(set, 1, dx, dy);
	e = refresh_pw(set, 2, dx, dy);
	while (set->map[(int)e][(int)i] != '4' && set->map[(int)e][(int)i] != '5'
		&& set->map[(int)e][(int)i] != '1' && set->map[(int)e][(int)i] != ' ')
	{
		set->pre_wall += speed_moove(set) / ((float)set->res_x / 20);
		i = refresh_pw(set, 1, dx, dy);
		e = refresh_pw(set, 2, dx, dy);
	}
	if (set->map[(int)e][(int)i] == '4' || set->map[(int)e][(int)i] == '5')
		return (1);
	return (0);
}

void	align_text(t_param *set)
{
	float f_ang;
	float f_dx;
	float f_dy;

	f_ang = set->angle - M_PI / (set->res_x * 4);
	f_dx = cos(f_ang);
	f_dy = sin(f_ang);
	set->pre_wall = 0;
	while ((pre_wall(set, f_dx, f_dy)) == 1)
	{
		set->xspe += (set->pre_wall / (float)(set->res_y
			* (set->size_cub) / 32));
		if (set->xspe > 64)
			set->xspe = 0;
		f_ang = f_ang - M_PI / (set->res_x * 4);
		f_dx = cos(f_ang);
		f_dy = sin(f_ang);
		set->pre_wall = 0;
	}
	set->xspe += (set->pre_wall / (float)(set->res_y
		* (set->size_cub) / 32));
}

void	pres_sprite(t_param *set)
{
	float	v;
	float	p;

	if (set->spr_pres == 1)
	{
		set->lgr_spr -= speed_moove(set);
		v = ((set->perso_x + ((set->dx * set->lgr_spr)))
			- set->start_size) / set->size_cub;
		p = ((set->perso_y + ((set->dy * set->lgr_spr)))
			- set->start_size) / set->size_cub;
		while (set->map[(int)p][(int)v] != '6')
		{
			set->lgr_spr += speed_moove(set) / ((float)set->res_x / 20);
			v = ((set->perso_x + ((set->dx * set->lgr_spr)))
				- set->start_size) / set->size_cub;
			p = ((set->perso_y + ((set->dy * set->lgr_spr)))
				- set->start_size) / set->size_cub;
		}
	}
	set->xspe_spr += (set->lgr_spr / ((float)(set->res_y * set->res_x) / 12500));
}
