/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:57:08 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/12 11:58:09 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_open(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 1)
		return (-1);
	return (0);
}

int		trim_reso(char *line, int *n, t_param *set)
{
	int		i;
	char	*nbr;

	i = 1;
	while (line[i] == ' ')
		i++;
	set->res_x = ft_atoi(&line[i]);
	while ((line[i] >= '0' && line[i] <= '9') || line[i] == '-' || line[i] == '+')
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
		{
			i++;
		}
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return(error_color(1));
		i++;
		set->f_g = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]) == 1 && line[i])
			i++;
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return(error_color(1));
		i++;
		set->f_b = ft_atoi(&line[i]);
	}
	if (set->f_r < 0 || set->f_g < 0 || set->f_b < 0)
		return(error_color(1));
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
		{
			i++;
		}
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return(error_color(1));
		i++;
		set->c_g = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]) == 1 && line[i])
			i++;
		if (line[i] != ',' || ft_isdigit(line[i + 1]) == 0)
			return(error_color(1));
		i++;
		set->c_b = ft_atoi(&line[i]);

	}
	if (set->c_r < 0 || set->c_g < 0 || set->c_b < 0)
		return(error_color(2));
	(*n)++;
	return (1);
}

int		next_gnl(char *str, int *n, t_param *set)
{
	int i;

	i = 0;
	//printf("str = %s\n", str);
	while (str[i] || (str[0] == '\0' && *n == 8 && set->size_map != 0))
	{
		if (str[i] == 'R' && *n == 0)
			return (trim_reso(&str[i], n, set));
		if ((str[i] == 'N' && str[i + 1] == 'O') && *n == 1)
			return (trim_textno(&str[i], n, set));
		if ((str[i] == 'S' && str[i + 1] == 'O') && *n == 2)
			return (trim_textso(&str[i], n, set));
		if ((str[i] == 'W' && str[i + 1] == 'E') && *n == 3)
			return (trim_textwe(&str[i], n, set));
		if ((str[i] == 'E' && str[i + 1] == 'A') && *n == 4)
			return (trim_textea(&str[i], n, set));
		if (str[i] == 'S' && *n == 5)
			return (trim_texts(&str[i], n, set));
		if (str[i] == 'F' && *n == 6)
			return (clr_ground(&str[i], n, set));
		if (str[i] == 'C' && *n == 7)
			return (clr_ceiling(&str[i], n, set));
		if (*n == 8)
			return (check_map(str, set));
		if (str[i] != ' ')
			return (error_param());
		i++;
	}
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
	n = 0;
	k = 1;
	l = 1;
	while (l == 1 && k == 1)
	{
		k = get_next_line(fd, line);
		l = next_gnl(*line, &n, set);
	}
	//printf("set->cpy = \n%s\n", set->cpy);
	set->map = ft_split(set->cpy, '\n');
	//printf("\nsplit : |%s|\n", set->map[0]);
	print_struct(set);

	free(line);
}
