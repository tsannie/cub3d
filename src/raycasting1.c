/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:46:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 15:21:33 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_color_wall(t_param *set, float x, float y)
{
	set->yspe += (set->lgr / (float)(set->res_y * (set->size_cub) / 32));
	if (set->yspe > 64)
		set->yspe = 64;
	if (((y <= set->res_y) && (y >= 0)) && ((x <= set->res_x) && (x >= 0)))
		my_mlx_pixel_put(set, x, y, (((set->T_r & 0xff) << 16)
			+ ((set->T_g & 0xff) << 8) + (set->T_b & 0xff)));
}

void	color_wall(t_param *set, char *addr, int l_lenght, int *cord)
{
	float x;
	float y;

	set->yspe = 0;
	set->xspe += (set->lgr / (float)(set->res_y * (set->size_cub) / 32));
	if (set->xspe > 64)
		set->xspe = 0;
	x = cord[0];
	y = 0;
	while (y < cord[1])
	{
		my_mlx_pixel_put(set, x, y, create_color(set->c_r, set->c_g, set->c_b));
		y++;
	}
	y = cord[1];
	while (y < cord[3])
	{
		set->T_r = addr[(((int)set->yspe) * l_lenght)
			+ ((int)set->xspe * 4) + 2];
		set->T_g = addr[(((int)set->yspe) * l_lenght)
			+ ((int)set->xspe * 4) + 1];
		set->T_b = addr[(((int)set->yspe) * l_lenght)
			+ ((int)set->xspe * 4) + 0];
		put_color_wall(set, x, y);
		y++;
	}
	while (y <= set->res_y)
	{
		my_mlx_pixel_put(set, x, y, create_color(set->f_r, set->f_g, set->f_b));
		y++;
	}
}

int		ray_cast(t_param *set, float lgr, char *addr, int l_lenght)
{
	float	size_column;
	int		*cord;

	if (!(cord = malloc(sizeof(int) * 5)))
		return (error_param(2));
	size_column = (float)(set->res_y * (set->size_cub) * 2) / lgr;
	set->i_line++;
	cord[0] = 1 * (float)set->i_line;
	cord[1] = ((float)set->res_y / 2) - (size_column / 2);
	cord[2] = 1 * ((float)set->i_line + 1);
	cord[3] = ((float)set->res_y / 2) + (size_column / 2);
	set->lgr = lgr;
	if (cord[0] > set->res_x)
		cord[0] = set->res_x;
	if (cord[2] > set->res_x)
		cord[2] = set->res_x;
	if (cord[3] > set->res_y)
		cord[3] = set->res_y;
	color_wall(set, addr, l_lenght, cord);
	if (set->sprite == 1 && set->xspe_spr < 64)
		if (print_spite(set) == -1)
			return (-1);
	free(cord);
	return (0);
}

int		ray(t_param *set, float lgr)
{
	if (set->map[(int)set->e][(int)set->i] == '4')
	{
		if (((set->angle > 0 && set->angle < M_PI) || set->angle < -M_PI))
		{
			if (ray_cast(set, lgr, set->addrS, set->line_lengthS) == -1)
				return (-1);
		}
		else
		{
			if (ray_cast(set, lgr, set->addrN, set->line_lengthN) == -1)
				return (-1);
		}
	}
	else
	{
		if (((set->angle > -M_PI_2 && set->angle < M_PI_2)))
		{
			if (ray_cast(set, lgr, set->addrE, set->line_lengthE) == -1)
				return (-1);
		}
		else
			return (ray_cast(set, lgr, set->addrW,
				set->line_lengthW) == -1 ? -1 : 0);
	}
	return (0);
}

int		print_line(t_param *set)
{
	float lgr;
	float lgr_correct;

	middle_point(set);
	set->xspe = 0;
	set->angle = set->orient_p - M_PI / 8;
	while (set->angle <= (set->orient_p + (M_PI / 8)))
	{
		set->sprite = 0;
		lgr = search_wall(set);
		lgr_correct = lgr * cos(set->orient_p - set->angle);
		lgr -= 0.2;
		set->i = ((set->perso_x + ((set->dx * lgr)))
			- set->start_size) / set->size_cub;
		ray(set, lgr_correct);
		set->angle = set->angle + M_PI / (set->res_x * 4);
	}
	wash_map(set);
	minimap(set, -2);
	return (0);
}
