/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:43:10 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/26 17:05:01 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		pre_wall(t_param *set, float angle, float dx, float dy)
{
	float	i;
	float	e;

	i = ((set->perso_x + ((dx * set->pre_wall))) - set->start_size) / set->size_cub;
	e = ((set->perso_y + ((dy * set->pre_wall))) - set->start_size) / set->size_cub;
	//printf("Avant je suis sur '%c'(%d)(%d)\n", set->map[(int)e][(int)i], (int)e, (int)i);
	while (set->map[(int)e][(int)i] != '4' && set->map[(int)e][(int)i] != '5' && set->map[(int)e][(int)i] != '1' && set->map[(int)e][(int)i] != ' ' )
	{
		printf("je suis sur '%c'(%d)(%d)\n", set->map[(int)e][(int)i], (int)e, (int)i);
		set->pre_wall += speed_moove(set);
		i = ((set->perso_x + ((dx * set->pre_wall))) - set->start_size) / set->size_cub;
		e = ((set->perso_y + ((dy * set->pre_wall))) - set->start_size) / set->size_cub;
	}
	set->pre_wall -= speed_moove(set);
	i = ((set->perso_x + ((dx * set->pre_wall))) - set->start_size) / set->size_cub;
	e = ((set->perso_y + ((dy * set->pre_wall))) - set->start_size) / set->size_cub;
	while (set->map[(int)e][(int)i] != '4' && set->map[(int)e][(int)i] != '5' && set->map[(int)e][(int)i] != '1' && set->map[(int)e][(int)i] != ' ' )
	{
		set->pre_wall += speed_moove(set) / ((float)set->res_x / 20);
		i = ((set->perso_x + ((dx * set->pre_wall))) - set->start_size) / set->size_cub;
		e = ((set->perso_y + ((dy * set->pre_wall))) - set->start_size) / set->size_cub;
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

	printf("entre\n");
	f_ang = set->angle - M_PI / (set->res_x * 4);
	f_dx = cos(f_ang);
	f_dy = sin(f_ang);
	set->pre_wall = 0;
	printf("b = %f\n", set->xspe);
	while ((pre_wall(set, f_ang, f_dx, f_dy)) == 1)
	{
		set->xspe += (set->pre_wall / (float)(set->res_y * (set->size_cub) / 32));
		if (set->xspe > 64)
			set->xspe = 0;
		printf("%f\n", set->xspe);
		f_ang = f_ang - M_PI / (set->res_x * 4);
		f_dx = cos(f_ang);
		f_dy = sin(f_ang);
		set->pre_wall = 0;
	}
	set->xspe += (set->pre_wall / (float)(set->res_y * (set->size_cub) / 32));
}

float	search_wall(t_param *set)
{
	float lgr;

	lgr = 0;
	set->dx = cos(set->angle);
	set->dy = sin(set->angle);
	set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
	set->e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
	while (set->map[(int)set->e][(int)set->i] != '1' && set->map[(int)set->e][(int)set->i] != ' ' && set->map[(int)set->e][(int)set->i] != '4' && set->map[(int)set->e][(int)set->i] != '5')
	{
		//printf("lgr = %f | set->map[e][i] = |%c|\n", lgr, set->map[(int)set->e][(int)set->i]);
		set->cpt++;
		lgr += speed_moove(set);
		set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
		set->e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
		//my_mlx_pixel_put(set, i * set->size_cub + set->start_size, e * set->size_cub + set->start_size, create_color(0, 176, 0, 144));
	}
	lgr -= speed_moove(set);
	set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
	set->e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
	while (set->map[(int)set->e][(int)set->i] != '1' && set->map[(int)set->e][(int)set->i] != ' ' && set->map[(int)set->e][(int)set->i] != '4' && set->map[(int)set->e][(int)set->i] != '5')
	{
		set->cpt++;
		lgr += speed_moove(set) / ((float)set->res_x / 20);
		set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
		set->e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
		//my_mlx_pixel_put(set, i * set->size_cub + set->start_size, e * set->size_cub + set->start_size, create_color(0, 176, 0, 144));
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
	if (set->i_line == -1)
		align_text(set);
	//printf("\n\nBefore:\ne = %f | i = %f | set->map[e][i] = |%c|\nlgr = %f\n",set->e,set->i, set->map[(int)set->e][(int)set->i], lgr);
	return (lgr);
}

void 	wash_map(t_param *set)
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
