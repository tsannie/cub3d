/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:32 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/14 17:43:37 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	colision(t_param *set, int a)
{
	int		*cord;
	int		e;
	int		i;
	int		g;
	float	cote;

	if (a == 1)
	{
		g = (set->pps_x + (set->ppe_x - set->pps_x) - set->start_x) / set->size_cub;
		i = (set->pps_y - set->start_y) / set->size_cub;
		e = (set->pps_x - set->start_x) / set->size_cub;
		if (set->map[i][e] == '1' || set->map[i][g] == '1')
		{
			set->pps_y = set->pps_y + (set->size_cub / 10);
			set->ppe_y = set->ppe_y + (set->size_cub / 10);
		}
	}
	if (a == 2)
	{
		g = (set->ppe_x - (set->ppe_x - set->pps_x) - set->start_x) / set->size_cub;
		i = (set->ppe_y - set->start_y) / set->size_cub;
		e = (set->ppe_x - set->start_x) / set->size_cub;
		if (set->map[i][e] == '1' || set->map[i][g] == '1')
		{
			set->pps_y = set->pps_y - (set->size_cub / 10);
			set->ppe_y = set->ppe_y - (set->size_cub / 10);
		}
	}
	if (a == 3)
	{
		g = (set->pps_y + (set->ppe_x - set->pps_x) - set->start_x) / set->size_cub;
		i = (set->pps_y - set->start_y) / set->size_cub;
		e = (set->pps_x - set->start_x) / set->size_cub;
		if (set->map[i][e] == '1' || set->map[g][e] == '1')
		{
			set->pps_x = set->pps_x + (set->size_cub / 10);
			set->ppe_x = set->ppe_x + (set->size_cub / 10);
		}
	}
	if (a == 4)
	{
		g = (set->ppe_y - (set->ppe_x - set->pps_x) - set->start_x) / set->size_cub;
		i = (set->ppe_y - set->start_y) / set->size_cub;
		e = (set->ppe_x - set->start_x) / set->size_cub;
		if (set->map[i][e] == '1' || set->map[g][e] == '1')
		{
			set->pps_x = set->pps_x - (set->size_cub / 10);
			set->ppe_x = set->ppe_x - (set->size_cub / 10);
		}
	}
	print_square(set, cord = create_coord(set->pps_x, set->pps_y,
		set->ppe_x, set->ppe_y), create_color(0, 46, 219, 12));
	free(cord);
}

int	moove_player(int keycode, t_param *set)
{
	printf("key = [%d]\n", keycode);
	printf("size_cub = [%f]\n", set->size_cub);
	printf("melange = [%f]\n", set->size_cub / 10);
	if (keycode == 13)
	{
		set->pps_y = set->pps_y - (set->size_cub / 10);
		set->ppe_y = set->ppe_y - (set->size_cub / 10);
		minimap(set, 1);
	}
	if (keycode == 1)
	{
		set->pps_y = set->pps_y + (set->size_cub / 10);
		set->ppe_y = set->ppe_y + (set->size_cub / 10);
		minimap(set, 2);
	}
	if (keycode == 0)
	{
		set->pps_x = set->pps_x - (set->size_cub / 10);
		set->ppe_x = set->ppe_x - (set->size_cub / 10);
		minimap(set, 3);
	}
	if (keycode == 2)
	{
		set->pps_x = set->pps_x + (set->size_cub / 10);
		set->ppe_x = set->ppe_x + (set->size_cub / 10);
		minimap(set, 4);
	}

	if (keycode == 124)
	{
		set->orient_p = set->orient_p - M_PI/24;
		minimap(set, 0);
	}
	if (keycode == 123)
	{
		set->orient_p = set->orient_p + M_PI/24;
		minimap(set, 0);
	}
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	return (0);
}