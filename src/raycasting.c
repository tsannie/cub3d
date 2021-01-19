/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:46:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/19 17:13:43 by tsannie          ###   ########.fr       */
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
	printf("\nlgr = %f\n", lgr);
	size_column = (float)(set->res_y * 40) / lgr;
	thickness = (float)set->res_x / 512;
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
	printf("x1 = %d\ny1 = %d\nx2 = %d\ny2 = %d\n",cord[0], cord[1], cord[2], cord[3]);

	print_square(set, cord , clr);
	free(cord);

	printf("size_column = %f\nthickness = %f\ni_line = %d\n", size_column, thickness, set->i_line);
}

float	incr_decr(char a, char ei, t_param *set)
{
	float	res;

	if (ei == 'i')
	{
		if (a == '-')
			set->dx = (set->dx - (cos(set->angle)) / 20);
		if (a == '+')
			set->dx = (set->dx + (cos(set->angle)) / 20);
		res = (set->dx - set->start_size) / (set->size_cub);
	}
	if (ei == 'e')
	{
		if (a == '-')
			set->dy = (set->dy - (cos(set->angle)) / 20);
		if (a == '+')
			set->dy = (set->dy + (cos(set->angle)) / 20);
		res = (set->dy - set->start_size) / (set->size_cub);
	}
	return (res);
}

void	print_line(t_param *set)
{
	float i;
	float e;

	int cpt;
	float lgr;

	set->angle = set->orient_p - M_PI / 8;
	middle_point(set);

	cpt = 1;

	while (set->angle <= (set->orient_p + (M_PI / 8)))
	{
		set->dx = set->perso_x;
		set->dy = set->perso_y;
		i = (set->dx - set->start_size) / set->size_cub;
		e = (set->dy - set->start_size) / set->size_cub;
		lgr = 0;
		printf("\n\n\n----------------------------------------------------\nligne numero : %d\n",cpt);
		while (set->map[(int)e][(int)i] != '1' && set->map[(int)e][(int)i] != ' ')
		{
			set->dx = (set->dx + (cos(set->angle)) / 20);
			set->dy = (set->dy + (sin(set->angle)) / 20);
			i = (set->dx - set->start_size) / (set->size_cub);
			e = (set->dy - set->start_size) / (set->size_cub);
			my_mlx_pixel_put(set, set->dx, set->dy, create_color(0, 176, 0, 144));
			//printf("%f / ", lgr);
			lgr += 0.2;
		}
		/*set->dx = (set->dx - (cos(set->angle)) / 20);
		set->dy = (set->dy - (sin(set->angle)) / 20);
		i = (set->dx - set->start_size) / (set->size_cub);
		e = (set->dy - set->start_size) / (set->size_cub);*/

		//if (set->map[(int)e][(int)i] != '1')
		ray_cast(set, lgr, create_color(0, 55, 23, 108));
		cpt++;
		set->angle = set->angle + M_PI / 2048;
	}
	//minimap(set, -2);
}