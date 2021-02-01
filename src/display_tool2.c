/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tool2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:46:26 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 12:17:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		while_space(int i, char *line, int a)
{
	if (a == 1)
	{
		while (line[i] == ' ')
			i++;
	}
	else if (a == 2)
	{
		while (ft_isdigit(line[i]) == 1 && line[i])
			i++;
	}
	else if (a == 3)
	{
		i = while_space(i, line, 2);
		while (line[i])
		{
			if (line[i] != ' ')
				return (-1);
			i++;
		}
	}
	return (i);
}

void	print_ground(t_param *set, int a, int *cord)
{
	float x;
	float y;

	x = cord[0];
	if (a == 0)
	{
		y = 0;
		while (y < cord[1])
		{
			my_mlx_pixel_put(set, x, y, create_color(set->c_r,
				set->c_g, set->c_b));
			y++;
		}
	}
	if (a == 1)
	{
		y = cord[3];
		while (y <= set->res_y)
		{
			my_mlx_pixel_put(set, x, y, create_color(set->f_r,
				set->f_g, set->f_b));
			y++;
		}
	}
}

void	save_pos(t_param *set)
{
	float	size;

	size = set->size_cub / 3;
	set->pps_x = set->s_x + (size);
	set->pps_y = set->s_y + (size);
	set->ppe_x = set->e_x - (size);
	set->ppe_y = set->e_y - (size);
}

int		create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_param *set, int x, int y, int color)
{
	char	*dst;

	dst = set->addr + (y * set->line_length + x * (set->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
