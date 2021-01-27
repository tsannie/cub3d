/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:32 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/27 16:55:35 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_win(int keycode, t_param *set)
{
	printf("button = [%d]\n", keycode);
	if (set->img)
		mlx_destroy_image(set->mlx, set->img);
	exit(0);
}

int	next_moove2(int keycode, t_param *set)
{
	if (keycode == 123) // turn_left
	{
		set->orient_p = (set->orient_p <= -M_PI) ? M_PI - M_PI / 24
		: set->orient_p - M_PI / 24;
		minimap(set, 0);
	}
	else if (keycode == 124) // turn_right
	{
		set->orient_p = (set->orient_p >= M_PI) ? -M_PI + M_PI / 24
				: set->orient_p + M_PI / 24;
		minimap(set, 0);
	}
	else if (keycode == 53) //exit
		exit_win(-1, set);
	return (0);
}

int	next_moove1(int keycode, t_param *set)
{
	if (keycode == 2) // right
	{
		set->pps_x = set->pps_x - (sin(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x - (sin(set->orient_p) * speed_moove(set));
		set->pps_y = set->pps_y + (cos(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y + (cos(set->orient_p) * speed_moove(set));
		minimap(set, 4);
	}
	else if (keycode == 0) //left
	{
		set->pps_x = set->pps_x + (sin(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x + (sin(set->orient_p) * speed_moove(set));
		set->pps_y = set->pps_y - (cos(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y - (cos(set->orient_p) * speed_moove(set));
		minimap(set, 3);
	}
	else
		next_moove2(keycode, set);
	return (0);
}

int	moove_player(int keycode, t_param *set)
{
	printf("key = [%d]\n", keycode);
	if (keycode == 13) //up
	{
		set->pps_y = set->pps_y + (sin(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y + (sin(set->orient_p) * speed_moove(set));
		set->pps_x = set->pps_x + (cos(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x + (cos(set->orient_p) * speed_moove(set));
		minimap(set, 1);
	}
	else if (keycode == 1) //down
	{
		set->pps_y = set->pps_y - (sin(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y - (sin(set->orient_p) * speed_moove(set));
		set->pps_x = set->pps_x - (cos(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x - (cos(set->orient_p) * speed_moove(set));
		minimap(set, 2);
	}
	else
		next_moove1(keycode, set);
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	return (0);
}
