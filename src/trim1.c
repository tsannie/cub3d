/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:57:08 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 01:41:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		while_space(int i, char *line, int a)
{
	if (a == 1)
	{
		while (line[i] == ' ')
			i++;
	}
	else if (a == 2)
	{
		while (ft_isdigit(line[i]) == 1 && line[i])
			i++;
	}
	else if (a == 3)
	{
		i = while_space(i, line, 2);
		while (line[i])
		{
			if (line[i] != ' ')
				return (-1);
			i++;
		}
	}
	return (i);
}

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
	close(fd);
	set->map = ft_split(set->cpy, '\n');
	return (0);
}
