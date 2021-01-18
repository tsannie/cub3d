/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:01:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/18 16:39:32 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_param *set, int x, int y, int color)
{
	char	*dst;

	dst = set->addr + (y * set->line_length + x * (set->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		*create_coord(int x_start, int y_start, int x_end, int y_end)
{
	int *cord;

	if (!(cord = malloc(sizeof(int) * 4)))
		return (0);
	cord[0] = x_start;
	cord[1] = y_start;
	cord[2] = x_end;
	cord[3] = y_end;
	return (cord);
}


void	print_line(t_param *set)
{
	float dx;
	float dy;
	int i;
	int e;
	int r;
	float angle;
	//int cpt;

	angle = set->orient_p - M_PI / 8;
	middle_point(set);
	//cpt = 0;
	while (angle <= (set->orient_p + (M_PI / 8)))
	{
		dx = set->perso_x;
		dy = set->perso_y;
		i = (dx - set->start_size) / set->size_cub;
		e = (dy - set->start_size) / set->size_cub;
		while (set->map[e][i] != '1' && set->map[e][i] != ' ')
		{
			my_mlx_pixel_put(set, dx, dy, create_color(0, 176, 0, 144));
			dx = dx + (cos(angle));
			dy = dy + (sin(angle));
			i = (dx - set->start_size) / set->size_cub;
			e = (dy - set->start_size) / set->size_cub;
		}
		//cpt++;
		angle = angle + M_PI / 1024;
	}
	//printf("cpt = {%d}\n", cpt);
}

void	middle_point(t_param *set)
{
	float cote;
	float e;

	cote = set->ppe_y - set->pps_y;
	e = cote / 2;
	set->perso_x = set->pps_x + e;
	set->perso_y = set->pps_y + e;
}

float	exter_point(t_param *set, float value, int a)
{
	float cote;
	float e;

	cote = set->ppe_y - set->pps_y;
	e = cote / 2;
	if (a == 1)
		return (value - e);
	if (a == 2)
		return (value+ e);
	if (a == 3)
		return (value - e);
	if (a == 4)
		return (value + e);
	return (0);
}

void	print_square(t_param *set, int *cord, int color)
{
	int i;
	int e;

	i = cord[0];
	while (i < cord[2])
	{
		e = cord[1];
		while (e < cord[3])
		{
			my_mlx_pixel_put(set, i, e, color);
			e++;
		}
		i++;
	}
}

void	set_orient(t_param *set)
{
	if (set->pos == 'S')
		set->orient_p = M_PI_2;
	if (set->pos == 'N')
		set->orient_p = -(M_PI/2);
	if (set->pos == 'E')
		set->orient_p = 0;
	if (set->pos == 'W')
		set->orient_p = M_PI;
}