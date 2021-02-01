/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:57:08 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 12:21:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		clr_ground(char *line, int *n, t_param *set)
{
	int	i;

	i = 1;
	i = while_space(i, line, 1);
	if (ft_isdigit(line[i]) == 1)
	{
		set->f_r = ft_atoi(&line[i]);
		i = while_space(i, line, 2);
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return (error_color(1));
		i++;
		set->f_g = ft_atoi(&line[i]);
		i = while_space(i, line, 2);
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return (error_color(1));
		i++;
		set->f_b = ft_atoi(&line[i]);
	}
	if ((ft_iscolor(set->f_r, set->f_g, set->f_b) == 0)
		|| (while_space(i, line, 3) == -1))
		return (error_color(1));
	(*n)++;
	return (1);
}

int		clr_ceiling(char *line, int *n, t_param *set)
{
	int	i;

	i = 1;
	i = while_space(i, line, 1);
	if (ft_isdigit(line[i]) == 1)
	{
		set->c_r = ft_atoi(&line[i]);
		i = while_space(i, line, 2);
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return (error_color(1));
		i++;
		set->c_g = ft_atoi(&line[i]);
		i = while_space(i, line, 2);
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return (error_color(1));
		i++;
		set->c_b = ft_atoi(&line[i]);
	}
	if ((ft_iscolor(set->c_r, set->c_g, set->c_b) == 0)
		|| (while_space(i, line, 3) == -1))
		return (error_color(2));
	(*n)++;
	return (1);
}

int		there_is_color(t_param *set)
{
	if (ft_iscolor(set->c_r, set->c_g, set->c_b) == 0)
		return (error_color(2));
	if (ft_iscolor(set->f_r, set->f_g, set->f_b) == 0)
		return (error_color(1));
	if (set->res_x == -1 || set->res_y == -1)
		return (error_reso(0));
	return (0);
}

int		there_is_map(t_param *set)
{
	if (!set->map)
		return (error_map(6));
	if (!set->map[0])
		return (error_map(6));
	return (0);
}

int		param_trim(char *str, t_param *set)
{
	int		fd;

	if (test_directo(str) == -1)
		return (-1);
	fd = open(str, O_RDONLY);
	if (fd < 1 || correct_name(str) == 0)
		return (error_text("le config file (.cub).\n", str));
	if (search_line(set, fd) == -1)
		return (-1);
	if (there_is_color(set) == -1)
		return (-1);
	if (all_text(set) == -1)
		return (-1);
	close(fd);
	set->map = ft_split(set->cpy, '\n');
	return (0);
}
