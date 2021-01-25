/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:01:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/23 19:18:20 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float		speed_moove(t_param *set)
{
	float speed;

	speed = set->size_cub / 5;
	return (speed);
}

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

void	 print_square(t_param *set, int *cord, int color)
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

void	assign_text(t_param *set, int a)
{
	if (a == 0)
		set->imgT = mlx_xpm_file_to_image(set->mlx, set->text_so, 150, 150);
	if (a == 1)
		set->imgT = mlx_xpm_file_to_image(set->mlx, set->text_no, 150, 150);
	if (a == 2)
		set->imgT = mlx_xpm_file_to_image(set->mlx, set->text_ea, 150, 150);
	if (a == 3)
		set->imgT = mlx_xpm_file_to_image(set->mlx, set->text_we, 150, 150);
	set->addrT = mlx_get_data_addr(set->imgT, &set->bits_per_pixelT, &set->line_lengthT, &set->endianT);
}
