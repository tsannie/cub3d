/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:48:32 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/21 17:04:20 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	colision(t_param *set, int a)
{
	int		*cord;
	int		e;
	int		i;
	int		g;
	int		p;

	if (a == 1)
	{
		g = (set->pps_x + (set->ppe_x - set->pps_x) - set->start_size) / set->size_cub;
		p = (set->pps_y + (set->ppe_x - set->pps_x) - set->start_size) / set->size_cub;
		i = (set->pps_y - set->start_size) / set->size_cub;
		e = (set->pps_x - set->start_size) / set->size_cub;
		if (set->map[i][e] == '1' || set->map[i][g] == '1' || set->map[p][g] == '1' || set->map[p][e] == '1'
			|| set->map[i][e] == '2' || set->map[i][g] == '2' || set->map[p][g] == '2' || set->map[p][e] == '2')
		{
			set->pps_y = set->pps_y - (sin(set->orient_p) * speed_moove(set));
			set->ppe_y = set->ppe_y - (sin(set->orient_p) * speed_moove(set));
			set->pps_x = set->pps_x - (cos(set->orient_p) * speed_moove(set));
			set->ppe_x = set->ppe_x - (cos(set->orient_p) * speed_moove(set));
		}
	}
	if (a == 2)
	{
		g = (set->ppe_x - (set->ppe_x - set->pps_x) - set->start_size) / set->size_cub;
		p = (set->ppe_y - (set->ppe_x - set->pps_x) - set->start_size) / set->size_cub;
		i = (set->ppe_y - set->start_size) / set->size_cub;
		e = (set->ppe_x - set->start_size) / set->size_cub;
		if (set->map[i][e] == '1' || set->map[i][g] == '1' || set->map[p][g] == '1' || set->map[p][e] == '1'
			|| set->map[i][e] == '2' || set->map[i][g] == '2' || set->map[p][g] == '2' || set->map[p][e] == '2')
		{
			set->pps_y = set->pps_y + (sin(set->orient_p) * speed_moove(set));
			set->ppe_y = set->ppe_y + (sin(set->orient_p) * speed_moove(set));
			set->pps_x = set->pps_x + (cos(set->orient_p) * speed_moove(set));
			set->ppe_x = set->ppe_x + (cos(set->orient_p) * speed_moove(set));
		}
	}
	if (a == 3)
	{
		g = (set->pps_y + (set->ppe_x - set->pps_x) - set->start_size) / set->size_cub;
		p = (set->pps_x + (set->ppe_x - set->pps_x) - set->start_size) / set->size_cub;
		i = (set->pps_y - set->start_size) / set->size_cub;
		e = (set->pps_x - set->start_size) / set->size_cub;
		if (set->map[i][e] == '1' || set->map[g][e] == '1' || set->map[g][p] == '1' || set->map[i][p] == '1'
			|| set->map[i][e] == '2' || set->map[g][e] == '2' || set->map[g][p] == '2' || set->map[i][p] == '2')
		{
			set->pps_x = set->pps_x - (sin(set->orient_p) * speed_moove(set));
			set->ppe_x = set->ppe_x - (sin(set->orient_p) * speed_moove(set));
			set->pps_y = set->pps_y + (cos(set->orient_p) * speed_moove(set));
			set->ppe_y = set->ppe_y + (cos(set->orient_p) * speed_moove(set));
		}
	}
	if (a == 4)
	{
		g = (set->ppe_y - (set->ppe_x - set->pps_x) - set->start_size) / set->size_cub;
		p = (set->ppe_x - (set->ppe_x - set->pps_x) - set->start_size) / set->size_cub;
		i = (set->ppe_y - set->start_size) / set->size_cub;
		e = (set->ppe_x - set->start_size) / set->size_cub;
		if (set->map[i][e] == '1' || set->map[g][e] == '1' || set->map[g][p] == '1' || set->map[i][p] == '1'
			|| set->map[i][e] == '2' || set->map[g][e] == '2' || set->map[g][p] == '2' || set->map[i][p] == '2')
		{
			set->pps_x = set->pps_x + (sin(set->orient_p) * speed_moove(set));
			set->ppe_x = set->ppe_x + (sin(set->orient_p) * speed_moove(set));
			set->pps_y = set->pps_y - (cos(set->orient_p) * speed_moove(set));
			set->ppe_y = set->ppe_y - (cos(set->orient_p) * speed_moove(set));
		}
	}
	print_square(set, cord = create_coord(set->pps_x, set->pps_y,
		set->ppe_x, set->ppe_y), create_color(0, 11, 13, 12));
	free(cord);
}

int	exit_win(int keycode, t_param *set)
{
	if (set->img)
		mlx_destroy_image(set->mlx, set->img);
	return (0);
}

int	moove_player(int keycode, t_param *set)
{
	printf("key = [%d]\n", keycode);
	//printf("size_cub = [%f]\n", set->size_cub);
	if (keycode == 13)
	{
		set->pps_y = set->pps_y + (sin(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y + (sin(set->orient_p) * speed_moove(set));
		set->pps_x = set->pps_x + (cos(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x + (cos(set->orient_p) * speed_moove(set));
		minimap(set, 1);
	}
	if (keycode == 1)
	{
		set->pps_y = set->pps_y - (sin(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y - (sin(set->orient_p) * speed_moove(set));
		set->pps_x = set->pps_x - (cos(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x - (cos(set->orient_p) * speed_moove(set));
		minimap(set, 2);
	}
	if (keycode == 0)
	{
		set->pps_x = set->pps_x + (sin(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x + (sin(set->orient_p) * speed_moove(set));
		set->pps_y = set->pps_y - (cos(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y - (cos(set->orient_p) * speed_moove(set));
		minimap(set, 3);
	}
	if (keycode == 2)
	{
		set->pps_x = set->pps_x - (sin(set->orient_p) * speed_moove(set));
		set->ppe_x = set->ppe_x - (sin(set->orient_p) * speed_moove(set));
		set->pps_y = set->pps_y + (cos(set->orient_p) * speed_moove(set));
		set->ppe_y = set->ppe_y + (cos(set->orient_p) * speed_moove(set));
		minimap(set, 4);
	}
	if (keycode == 123)
	{
		if (set->orient_p <= -M_PI)
			set->orient_p = M_PI - M_PI / 50;
		else
			set->orient_p = set->orient_p - M_PI / 50;
		minimap(set, 0);
	}
	if (keycode == 124)
	{
		if (set->orient_p >= M_PI)
			set->orient_p = -M_PI + M_PI / 50;
		else
			set->orient_p = set->orient_p + M_PI / 50;
		minimap(set, 0);
	}
	if (keycode == 53)
		exit_win(-1, set);
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	return (0);
}