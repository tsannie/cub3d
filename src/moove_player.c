/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:32 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/13 18:48:33 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	change_pos(t_param *set, int a)
{
	int		cord[4];

	if (a == 1)
	{
		set->pps_y = set->pps_y - 5;
		set->ppe_y = set->ppe_y - 5;
	}
	if (a == 2)
	{
		set->pps_y = set->pps_y + 5;
		set->ppe_y = set->ppe_y + 5;
	}
	if (a == 3)
	{
		set->pps_x = set->pps_x - 5;
		set->ppe_x = set->ppe_x - 5;
	}
	if (a == 4)
	{
		set->pps_x = set->pps_x + 5;
		set->ppe_x = set->ppe_x + 5;
	}
	print_square(set, create_coord(cord, set->pps_x, set->pps_y,
		set->ppe_x, set->ppe_y), create_color(0, 46, 219, 12));
}

int	moove_player(int keycode, t_param *set)
{
	printf("key = [%d]\n", keycode);
	if (keycode == 13)
		print_minimap(set, 1);
	if (keycode == 1)
		print_minimap(set, 2);
	if (keycode == 0)
		print_minimap(set, 3);
	if (keycode == 2)
		print_minimap(set, 4);
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	return (0);
}