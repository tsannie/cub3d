/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tool2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:46:26 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 15:18:19 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* void	print_ground2(t_param *set, int e)
{
	int	i;

	while (e < set->res_y)
	{
		i = 0;
		while (i < set->res_x)
		{
			my_mlx_pixel_put(set, i, e, create_color(set->f_r,
				set->f_g, set->f_b));
			i++;
		}
		e++;
	}
}

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
			my_mlx_pixel_put(set, i, e, create_color(set->c_r,
				set->c_g, set->c_b));
			i++;
		}
		e++;
	}
	print_ground2(set, e);
}
 */
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
