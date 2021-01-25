/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:46:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/23 19:40:43 by tsannie          ###   ########.fr       */
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

void	ray_cast(t_param *set, float lgr, int clr)
{
	float	size_column;
	float	thickness;
	int 	*cord;

	if (!(cord = malloc(sizeof(int) * 4)))
		return ;
	//printf("\nlgr = %f\n", lgr);
	size_column = (float)(set->res_y * (set->size_cub) * 2) / lgr;
	thickness = 1;
	set->i_line++;

	cord[0] = thickness * (float)set->i_line;
	cord[1] = (set->res_y / 2) - (size_column / 2);
	cord[2] = thickness * (set->i_line + 1);
	cord[3] = (set->res_y / 2) + (size_column / 2);

	if (cord[0] > set->res_x)
		cord[0] = set->res_x;
	if (cord[1] <= 0)
		cord[1] = 0;
	if (cord[2] > set->res_x)
		cord[2] = set->res_x;
	if (cord[3] > set->res_y)
		cord[3] = set->res_y;


	//printf("x1 = %d\ny1 = %d\nx2 = %d\ny2 = %d\n",cord[0], cord[1], cord[2], cord[3]);

	print_square(set, cord , clr);
	free(cord);

	//printf("size_column = %f\nthickness = %f\ni_line = %d\n", size_column, thickness, set->i_line);
}

/*float	incr_decr(char a, char ei, t_param *set, float lgr)
{
	float	res;

	if (ei == 'i')
	{
		if (a == '-')
			set->dx = ((set->dx) * lgr);
		else if (a == '+')
			set->dx = ((set->dx) + (cos(set->angle) * lgr));
		res = (set->dx - set->start_size) / (set->size_cub);
	}
	else if (ei == 'e')
	{
		if (a == '-')
			set->dy = ((set->dy) * lgr);
		//printf("size_cub = %f\n", set->size_cub);
		res = (set->dy - set->start_size) / (set->size_cub);
	}
	return (res);
}*/

void	print_line(t_param *set)
{
	float i;
	float e;

	int cpt;
	float lgr;
	float lgr_correct;

	middle_point(set);

	cpt = 0;

	set->angle = set->orient_p - M_PI / 8;
	//printf("\nPremier angle = %f\n", set->angle);
	while (set->angle <= (set->orient_p + (M_PI / 8)))
	{
		lgr = 0;
		set->dx = cos(set->angle);
		set->dy = sin(set->angle);
		i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
		e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
		//printf("\n\n\n----------------------------------------------------\n");
		while (set->map[(int)e][(int)i] != '1' && set->map[(int)e][(int)i] != ' ')
		{
			lgr += speed_moove(set);
			i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
			e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
			//printf("\ne = %f | i = %f\n", e, i);
			my_mlx_pixel_put(set, i * set->size_cub + set->start_size, e * set->size_cub + set->start_size, create_color(0, 176, 0, 144));
			cpt++;
			//printf("lgr = %f | ", lgr);
		}
		lgr -= speed_moove(set);
		i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
		e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
		cpt++;
		//printf("\nlgr = %f | ", lgr);
		//printf("\ne = %f | i = %f\n", e, i);
		while (set->map[(int)e][(int)i] != '1' && set->map[(int)e][(int)i] != ' ')
		{
			lgr += speed_moove(set) / 250;
			i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
			e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
			my_mlx_pixel_put(set, i * set->size_cub + set->start_size, e * set->size_cub + set->start_size, create_color(0, 176, 0, 144));
			cpt++;
			//printf("\nlgr = %f | ", lgr);
			//printf("\ne = %f | i = %f\n", e, i);
			//printf("yo");
		}
		lgr_correct = lgr * cos(set->orient_p - set->angle);

	//	printf(" lgr_af = %f\n", lgr);

		//printf("\ncos(dx) = %f | sin(dy) = %f\n", cos(i), sin(e));
		lgr -= 0.2;
		i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
		if (set->map[(int)e][(int)i] == '1')
		{
			if (((set->angle > 0 && set->angle < M_PI) || set->angle < -M_PI))
			{
				assign_text(set, 0);
				ray_cast(set, lgr_correct, create_color(0, 55, 23, 108)); // bleue SUD
			}
			else
			{
				assign_text(set, 1);
				ray_cast(set, lgr_correct, create_color(0, 234, 160, 45)); // orange NORD
			}
		}
		else
		{
			if (((set->angle > -M_PI_2 && set->angle < M_PI_2)))
			{
				assign_text(set, 2);
				ray_cast(set, lgr_correct, create_color(0, 138, 178, 50)); // vert EST
			}
			else
			{
				assign_text(set, 3);
				ray_cast(set, lgr_correct, create_color(0, 200, 40, 50)); //rouge OUEST
			}
		}

		set->angle = set->angle + M_PI / (set->res_x * 4);
	}
	printf("\ncpt = %d\n", cpt);
	//printf("\ndernier angle = %f\n", set->angle);
	//minimap(set, -2);
}
