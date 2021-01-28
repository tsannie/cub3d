/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:32:24 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 15:38:54 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_color_sprite(t_param *set, float x, float y)
{
	set->T_r = set->addrSp[(((int)set->yspe) * set->line_lengthSp)
		+ ((int)set->xspe_spr * 4) + 2];
	set->T_g = set->addrSp[(((int)set->yspe) * set->line_lengthSp)
		+ ((int)set->xspe_spr * 4) + 1];
	set->T_b = set->addrSp[(((int)set->yspe) * set->line_lengthSp)
		+ ((int)set->xspe_spr * 4) + 0];
	set->yspe += (set->lgr_spr / (float)(set->res_y * (set->size_cub) / 51));
	if (set->yspe > 64)
		set->yspe = 64;
	if (((y <= set->res_y) && (y >= 0)) && ((x <= set->res_x) && (x >= 0)))
	{
		if (set->T_r != 0 && set->T_g != 0 && set->T_b != 0)
			my_mlx_pixel_put(set, x, y, (((set->T_r & 0xff) << 16)
				+ ((set->T_g & 0xff) << 8) + (set->T_b & 0xff)));
	}
}

void	color_sprite(t_param *set, int *cord_s)
{
	float	x;
	float	y;

	set->yspe = 0;
	x = cord_s[0];
	while (x < cord_s[2])
	{
		y = cord_s[1];
		while (y < cord_s[3])
		{
			put_color_sprite(set, x, y);
			y++;
		}
		x++;
	}
}

int		print_spite(t_param *set)
{
	float	size_sprite;
	int		*cord_s;

	size_sprite = (float)(set->res_y * (set->size_cub / 4)) / set->lgr_spr;
	if (!(cord_s = malloc(sizeof(int) * 4)))
		return (error_param(2));
	cord_s[0] = 1 * (float)set->i_line;
	cord_s[1] = ((float)set->res_y / 2) - (size_sprite);
	cord_s[2] = 1 * ((float)set->i_line + 1);
	cord_s[3] = ((float)set->res_y / 2) + (size_sprite * 4);
	if (cord_s[0] > set->res_x)
		cord_s[0] = set->res_x;
	if (cord_s[2] > set->res_x)
		cord_s[2] = set->res_x;
	if (cord_s[3] > set->res_y)
		cord_s[3] = set->res_y;
	color_sprite(set, cord_s);
	free(cord_s);
	return (0);
}
