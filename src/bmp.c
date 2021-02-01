/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:06:44 by user42            #+#    #+#             */
/*   Updated: 2021/01/31 23:53:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_header(t_param *set, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * set->res_x * set->res_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &set->res_x, 4);
	write(fd, &set->res_y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &set->bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

int		ft_save(t_param *set)
{
	int	fd;
	int	x;
	int	y;

	y = set->res_y;
	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		return (-1);
	ft_header(set, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < set->res_x)
		{
			write(fd, &set->addr[y * set->line_length + x
				* (set->bits_per_pixel / 8)], 4);
			x++;
		}
		y--;
	}
	system("chmod 777 image.bmp");
	return (0);
}

int		bit_map(t_param *set)
{
	if (set->save == 1)
	{
		set->save = 0;
		if (ft_save(set) == -1)
			ft_putstr_fd("Error\n Il y a eu un probleme lors de la"
				" creation du .bmp\n", 1);
		leave_hook(set);
	}
	return (0);
}
