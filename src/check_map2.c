/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:05:49 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/27 17:33:34 by tsannie          ###   ########.fr       */
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
	if ((set->imgW = mlx_xpm_file_to_image(set->mlx, set->text_we,
		&i, &i)) == NULL)
		if (error_text("la texture OUEST\n", set->text_we) == -1)
			return (-1);
	set->addrW = mlx_get_data_addr(set->imgW, &set->bits_per_pixelW,
		&set->line_lengthW, &set->endianW);
	if ((set->imgSp = mlx_xpm_file_to_image(set->mlx, set->text_s,
		&i, &i)) == NULL)
		if (error_text("la texture du SPRITE\n", set->text_s) == -1)
			return (-1);
	set->addrSp = mlx_get_data_addr(set->imgSp, &set->bits_per_pixelSp,
		&set->line_lengthSp, &set->endianSp);
	return (0);
}

int		assign_text(t_param *set)
{
	int	i;

	i = 1;
	if ((set->imgS = mlx_xpm_file_to_image(set->mlx, set->text_so,
		&i, &i)) == NULL)
		if (error_text("la texture SUD\n", set->text_so) == -1)
			return (-1);
	set->addrS = mlx_get_data_addr(set->imgS, &set->bits_per_pixelS,
		&set->line_lengthS, &set->endianS);
	if ((set->imgN = mlx_xpm_file_to_image(set->mlx, set->text_no,
		&i, &i)) == NULL)
		if (error_text("la texture NORD\n", set->text_no) == -1)
			return (-1);
	set->addrN = mlx_get_data_addr(set->imgN, &set->bits_per_pixelN,
		&set->line_lengthN, &set->endianN);
	if ((set->imgE = mlx_xpm_file_to_image(set->mlx, set->text_ea,
		&i, &i)) == NULL)
		if (error_text("la texture EAST\n", set->text_ea) == -1)
			return (-1);
	set->addrE = mlx_get_data_addr(set->imgE, &set->bits_per_pixelE,
		&set->line_lengthE, &set->endianE);
	if (assign_text2(set) == -1)
		return (-1);
	return (0);
}
