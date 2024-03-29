/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:21:56 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 11:06:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		start_cub(t_param *set)
{
	set_orient(set);
	set->mlx = mlx_init();
	if (assign_text(set) == -1)
		leave_hook(set);
	mlx_get_screen_size(set->mlx, &set->screenx, &set->screeny);
	set->res_x = (set->res_x > set->screenx) ? set->screenx : set->res_x;
	set->res_y = (set->res_y > set->screeny) ? set->screeny : set->res_y;
	if (set->save == 0)
		set->win = mlx_new_window(set->mlx, set->res_x, set->res_y, "Cub3D !");
	set->img = mlx_new_image(set->mlx, set->res_x, set->res_y);
	set->addr = mlx_get_data_addr(set->img, &set->bits_per_pixel,
		&set->line_length, &set->endian);
	minimap(set, -1);
	bit_map(set);
	mlx_hook(set->win, 33, 1L << 17, leave_hook, set);
	mlx_hook(set->win, 2, 1L << 0, moove_player, set);
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	mlx_loop(set->mlx);
	return (0);
}
