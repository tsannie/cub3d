/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:05:49 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 11:21:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_space(t_param *set, int i, int e, int error)
{
	if (!set->map[i][e + 1] || !set->map[i][e - 1]
	|| set->map[i + 1] == NULL || set->map[i - 1] == NULL)
		return (error_map(error));
	if (set->map[i][e + 1] == ' ' || set->map[i][e - 1] == ' '
	|| set->map[i + 1][e] == ' ' || set->map[i - 1][e] == ' ')
		return (error_map(error));
	return (0);
}

int		logic_map(t_param *set)
{
	int		i;
	int		e;

	i = 0;
	while (set->map[i])
	{
		e = 0;
		while (set->map[i][e])
		{
			if (set->map[i][e] == set->pos)
				if (check_space(set, i, e, 3) == -1)
					return (-1);
			if (set->map[i][e] == '0')
				if (check_space(set, i, e, 4) == -1)
					return (-1);
			if (set->map[i][e] == '2')
				if (check_space(set, i, e, 5) == -1)
					return (-1);
			e++;
		}
		i++;
	}
	return (0);
}

int		assign_text2(t_param *set)
{
	int	i;

	i = 1;
	if ((set->imgw = mlx_xpm_file_to_image(set->mlx, set->text_we,
		&i, &i)) == NULL)
		if (error_text("la texture OUEST\n", set->text_we) == -1)
			return (-1);
	set->addrw = mlx_get_data_addr(set->imgw, &set->bits_per_pixelw,
		&set->line_lengthw, &set->endianw);
	if ((set->imgsp = mlx_xpm_file_to_image(set->mlx, set->text_s,
		&i, &i)) == NULL)
		return (error_text("la texture du SPRITE\n", set->text_s));
	set->addrsp = mlx_get_data_addr(set->imgsp, &set->bits_per_pixelsp,
		&set->line_lengthsp, &set->endiansp);
	return (0);
}

int		assign_text(t_param *set)
{
	int	i;

	i = 1;
	if ((set->imgs = mlx_xpm_file_to_image(set->mlx, set->text_so,
		&i, &i)) == NULL)
		if (error_text("la texture SUD\n", set->text_so) == -1)
			return (-1);
	set->addrs = mlx_get_data_addr(set->imgs, &set->bits_per_pixels,
		&set->line_lengths, &set->endians);
	if ((set->imgn = mlx_xpm_file_to_image(set->mlx, set->text_no,
		&i, &i)) == NULL)
		if (error_text("la texture NORD\n", set->text_no) == -1)
			return (-1);
	set->addrn = mlx_get_data_addr(set->imgn, &set->bits_per_pixeln,
		&set->line_lengthn, &set->endiann);
	if ((set->imge = mlx_xpm_file_to_image(set->mlx, set->text_ea,
		&i, &i)) == NULL)
		if (error_text("la texture EAST\n", set->text_ea) == -1)
			return (-1);
	set->addre = mlx_get_data_addr(set->imge, &set->bits_per_pixele,
		&set->line_lengthe, &set->endiane);
	if (assign_text2(set) == -1)
		return (-1);
	return (0);
}
