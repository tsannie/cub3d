/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:32 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 15:18:12 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	speed_moove(t_param *set)
{
	float	speed;

	speed = set->size_cub / 5;
	return (speed);
}

int		leave_hook(t_param *set)
{
	if (set->img)
		mlx_destroy_image(set->mlx, set->img);
	if (set->imgN)
		mlx_destroy_image(set->mlx, set->imgN);
	if (set->imgS)
		mlx_destroy_image(set->mlx, set->imgS);
	if (set->imgE)
		mlx_destroy_image(set->mlx, set->imgE);
	if (set->imgW)
		mlx_destroy_image(set->mlx, set->imgW);
	if (set->imgSp)
		mlx_destroy_image(set->mlx, set->imgSp);
	//mlx_clear_window(set->mlx, set->win);
	if (set->win)
		mlx_destroy_window(set->mlx, set->win);
	printf("hey");
	free_struct(set);
	exit(0);
}

int		next_moove2(int keycode, t_param *set)
{
	if (keycode == 65361)
	{
		set->orient_p = (set->orient_p <= -M_PI) ? M_PI - M_PI / 24
		: set->orient_p - M_PI / 24;
		if (minimap(set, 0) == -1)
			leave_hook(set);
	}
	else if (keycode == 65363)
	{
		set->orient_p = (set->orient_p >= M_PI) ? -M_PI + M_PI / 24
				: set->orient_p + M_PI / 24;
		if (minimap(set, 0) == -1)
			leave_hook(set);
	}
	else if (keycode == 53)
		leave_hook(set);
	return (0);
}

int		next_moove1(int keycode, t_param *set)
{
	if (keycode == 100)
	{
		set->pps_x = set->pps_x - (sin(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x - (sin(set->orient_p) * speed_moove(set));
		set->pps_y = set->pps_y + (cos(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y + (cos(set->orient_p) * speed_moove(set));
		if (minimap(set, 4) == -1)
			leave_hook(set);
	}
	else if (keycode == 97)
	{
		set->pps_x = set->pps_x + (sin(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x + (sin(set->orient_p) * speed_moove(set));
		set->pps_y = set->pps_y - (cos(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y - (cos(set->orient_p) * speed_moove(set));
		if (minimap(set, 3) == -1)
			leave_hook(set);
	}
	else
	{
		if (next_moove2(keycode, set) == -1)
			leave_hook(set);
	}
	return (0);
}

int		moove_player(int keycode, t_param *set)
{
	if (keycode == 119)
	{
		set->pps_y = set->pps_y + (sin(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y + (sin(set->orient_p) * speed_moove(set));
		set->pps_x = set->pps_x + (cos(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x + (cos(set->orient_p) * speed_moove(set));
		if (minimap(set, 1) == -1)
			leave_hook(set);
	}
	else if (keycode == 115)
	{
		set->pps_y = set->pps_y - (sin(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y - (sin(set->orient_p) * speed_moove(set));
		set->pps_x = set->pps_x - (cos(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x - (cos(set->orient_p) * speed_moove(set));
		if (minimap(set, 2) == -1)
			leave_hook(set);
	}
	else
	{
		if (next_moove1(keycode, set) == -1)
			leave_hook(set);
	}
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	return (0);
}
