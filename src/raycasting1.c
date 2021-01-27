/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:46:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/27 15:58:11 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_ground(t_param *set)
{
	int	i;
	int	e;
	int mid;

	mid = (set->res_y / 2);

	e = 0;
	while (e < mid)
	{
		i = 0;
		while (i < set->res_x)
		{
			my_mlx_pixel_put(set, i, e, create_color(0, set->c_r, set->c_g, set->c_b));
			i++;
		}
		e++;
	}
	while (e < set->res_y)
	{
		i = 0;
		while (i < set->res_x)
		{
			my_mlx_pixel_put(set, i, e, create_color(0, set->f_r, set->f_g, set->f_b));
			i++;
		}
		e++;
	}
}

void	ray_cast(t_param *set, float lgr, int or)
{
	float	size_column;
	float	thickness;
	int		*cord;
	int		*cord_s;
	float		x;
	float		y;
	int		i;
	int		e;
	float	yspe;
	float	size_sprite;

	if (!(cord = malloc(sizeof(int) * 4)))
		return ;

	//printf("\nlgr = %f\n", lgr);
	size_column = (float)(set->res_y * (set->size_cub) * 2) / lgr;
	thickness = 1;
	set->i_line++;

	cord[0] = thickness * (float)set->i_line;
	cord[1] = ((float)set->res_y / 2) - (size_column / 2);
	cord[2] = thickness * ((float)set->i_line + 1);
	cord[3] = ((float)set->res_y / 2) + (size_column / 2);

	if (cord[0] > set->res_x)
		cord[0] = set->res_x;
 	/* if (cord[1] < 0)
		cord[1] = 0; */
	if (cord[2] > set->res_x)
		cord[2] = set->res_x;
	if (cord[3] > set->res_y)
		cord[3] = set->res_y;


	//printf("x1 = %d | y1 = %d | x2 = %d | y2 = %d\n\n",cord[0], cord[1], cord[2], cord[3]);
	/* printf("RGB\nr = %d\ng = %d\nb = %d\n\n", set->T_r, set->T_g, set->T_b); */

	yspe = 0;
	set->xspe += (lgr / (float)(set->res_y * (set->size_cub) / 32));
	if (set->xspe > 64)
		set->xspe = 0;
	x = cord[0];
	while (x < cord[2])
	{
		y = cord[1];
		while (y < cord[3])
		{
			if (or == 0)
			{
				set->T_r = set->addrS[(((int)yspe) * set->line_lengthS) + ((int)set->xspe * 4) + 2];
				set->T_g = set->addrS[(((int)yspe) * set->line_lengthS) + ((int)set->xspe * 4) + 1];
				set->T_b = set->addrS[(((int)yspe) * set->line_lengthS) + ((int)set->xspe * 4) + 0];
			}
			else if (or == 1)
			{
				set->T_r = set->addrN[(((int)yspe) * set->line_lengthN) + ((int)set->xspe * 4) + 2];
				set->T_g = set->addrN[(((int)yspe) * set->line_lengthN) + ((int)set->xspe * 4) + 1];
				set->T_b = set->addrN[(((int)yspe) * set->line_lengthN) + ((int)set->xspe * 4) + 0];
			}
			else if (or == 2)
			{
				set->T_r = set->addrE[(((int)yspe) * set->line_lengthE) + ((int)set->xspe * 4) + 2];
				set->T_g = set->addrE[(((int)yspe) * set->line_lengthE) + ((int)set->xspe * 4) + 1];
				set->T_b = set->addrE[(((int)yspe) * set->line_lengthE) + ((int)set->xspe * 4) + 0];
			}
			else if (or == 3)
			{
				set->T_r = set->addrW[(((int)yspe) * set->line_lengthW) + ((int)set->xspe * 4) + 2];
				set->T_g = set->addrW[(((int)yspe) * set->line_lengthW) + ((int)set->xspe * 4) + 1];
				set->T_b = set->addrW[(((int)yspe) * set->line_lengthW) + ((int)set->xspe * 4) + 0];
			}
			yspe += (lgr / (float)(set->res_y * (set->size_cub) / 32));
			if (yspe > 64)
				yspe = 64;
			//if (((x < set->res_x) && (x > 0)))
			if (((y <= set->res_y) && (y >= 0)) && ((x <= set->res_x) && (x >= 0)))
				my_mlx_pixel_put(set, x, y, (((set->T_r & 0xff) << 16) + ((set->T_g & 0xff) << 8) +(set->T_b & 0xff)));
			y++;
		}
		x++;
		//printf("yspe = %f | set->xspe = %f\n", yspe, set->xspe);
	}

	if (set->sprite == 1 && set->xspe_spr < 64)
	{
		printf("%f | ", set->lgr_spr);
		//printf("hey");
		size_sprite = (float)(set->res_y * (set->size_cub / 4)) / set->lgr_spr;
		if (!(cord_s = malloc(sizeof(int) * 4)))
			return ;
		cord_s[0] = thickness * (float)set->i_line;
		cord_s[1] = ((float)set->res_y / 2) - (size_sprite);
		cord_s[2] = thickness * ((float)set->i_line + 1);
		cord_s[3] = ((float)set->res_y / 2) + (size_sprite * 4);

		if (cord_s[0] > set->res_x)
			cord_s[0] = set->res_x;
 		/* if (cord[1] < 0)
			cord[1] = 0; */
		if (cord_s[2] > set->res_x)
			cord_s[2] = set->res_x;
		if (cord_s[3] > set->res_y)
			cord_s[3] = set->res_y;

		yspe = 0;
		x = cord_s[0];
		while (x < cord_s[2])
		{
			y = cord_s[1];
			while (y < cord_s[3])
			{
				set->T_r = set->addrSp[(((int)yspe) * set->line_lengthSp) + ((int)set->xspe_spr * 4) + 2];
				set->T_g = set->addrSp[(((int)yspe) * set->line_lengthSp) + ((int)set->xspe_spr * 4) + 1];
				set->T_b = set->addrSp[(((int)yspe) * set->line_lengthSp) + ((int)set->xspe_spr * 4) + 0];
				yspe += (set->lgr_spr / (float)(set->res_y * (set->size_cub) / 47));

				//printf("RGB\nr = %d\ng = %d\nb = %d\n\n", set->T_r, set->T_g, set->T_b);
				if (yspe > 64)
					yspe = 64;
				if (((y <= set->res_y) && (y >= 0)) && ((x <= set->res_x) && (x >= 0)))
				{
					if (set->T_r != 0 && set->T_g != 0 && set->T_b != 0 )
						my_mlx_pixel_put(set, x, y, (((set->T_r & 0xff) << 16) + ((set->T_g & 0xff) << 8) +(set->T_b & 0xff)));
				}
				y++;
			}
			x++;
			//printf("yspe = %f | set->xspe = %f\n", yspe, set->xspe);
		}
		free(cord_s);
	}

	free(cord);

	//printf("size_column = %f\nthickness = %f\ni_line = %d\n", size_column, thickness, set->i_line);
}

void	print_line(t_param *set)
{

	float lgr;
	float lgr_correct;

	middle_point(set);

	set->cpt = 0;
	set->xspe = 0;

	set->angle = set->orient_p - M_PI / 8;
	//printf("\nPremier angle = %f\n", set->angle);
	while (set->angle <= (set->orient_p + (M_PI / 8)))
	{
		set->sprite = 0;
		lgr = search_wall(set);

		//set->lgr_spr = set->lgr_spr * cos(set->orient_p - set->angle); //pas sur

		lgr_correct = lgr * cos(set->orient_p - set->angle);

		//printf(" lgr_af = %f\n", lgr);

		//printf("\ncos(dx) = %f | sin(dy) = %f\n", cos(i), sin(e));
		//printf("lgr = %f", lgr);
		lgr -= 0.2;
		set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
		//printf("After:\ne = %f | i = %f | set->map[e][i] = |%c|\nlgr = %f\n",set->e,set->i, set->map[(int)set->e][(int)set->i], lgr);
		if (set->map[(int)set->e][(int)set->i] == '4')
		{
			if (((set->angle > 0 && set->angle < M_PI) || set->angle < -M_PI))
			{
				ray_cast(set, lgr_correct, 0); // bleue SUD
			}
			else
			{
				ray_cast(set, lgr_correct, 1); // orange NORD
			}
		}
		else
		{
			if (((set->angle > -M_PI_2 && set->angle < M_PI_2)))
			{
				ray_cast(set, lgr_correct, 2); // vert EST
			}
			else
			{
				ray_cast(set, lgr_correct, 3); //rouge OUEST
			}
		}

		set->angle = set->angle + M_PI / (set->res_x * 4);
	}
	printf("\ncpt = %d\n", set->cpt);
	wash_map(set);
	//printf("\ndernier angle = %f\n", set->angle);
	minimap(set, -2);
}
