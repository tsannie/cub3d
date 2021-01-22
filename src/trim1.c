/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:57:08 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/22 12:07:41 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_open(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int		trim_reso(char *line, int *n, t_param *set)
{
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	set->res_x = ft_atoi(&line[i]);
	while ((line[i] >= '0' && line[i] <= '9')
	|| line[i] == '-' || line[i] == '+')
	{
		i++;
	}
	set->res_y = ft_atoi(&line[i]);
	if (set->res_x < 1 || set->res_y < 1)
		return (error_reso());
	(*n)++;
	return (1);
}

int		clr_ground(char *line, int *n, t_param *set)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) == 1)
	{
		set->f_r = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]) == 1 && line[i])
			i++;
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return (error_color(1));
		i++;
		set->f_g = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]) == 1 && line[i])
			i++;
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return (error_color(1));
		i++;
		set->f_b = ft_atoi(&line[i]);
	}
	if (ft_iscolor(set->f_r, set->f_g, set->f_b) == 0)
		return (error_color(1));
	(*n)++;
	return (1);
}

int		clr_ceiling(char *line, int *n, t_param *set)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) == 1)
	{
		set->c_r = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]) == 1 && line[i])
			i++;
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return (error_color(1));
		i++;
		set->c_g = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]) == 1 && line[i])
			i++;
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return (error_color(1));
		i++;
		set->c_b = ft_atoi(&line[i]);
	}
	if (ft_iscolor(set->c_r, set->c_g, set->c_b) == 0)
		return (error_color(2));
	(*n)++;
	return (1);
}

int		param_trim(char *str, t_param *set)
{
	int		fd;
	char	**line;
	int		n;
	int		k;
	int		l;

	if (!(line = malloc(sizeof(char**))))
		return (-1);
	fd = open(str, O_RDONLY);
	if (fd < 1 || correct_name(str) == 0)
		return (error_text("le config file (.cub).\n", str));
	n = 0;
	k = 1;
	l = 1;
	while (l == 1 && k == 1)
	{
		k = get_next_line(fd, line);
		if ((l = next_gnl(*line, &n, set)) == -1)
			return (-1);
		free(*line);
	}
	close(fd);
	set->map = ft_split(set->cpy, '\n');
	free(line);
	return (0);
}
