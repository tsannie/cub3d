/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:39:38 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 02:00:58 by user42           ###   ########.fr       */
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
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	set->res_y = ft_atoi(&line[i]);
	if (set->res_x < 200 || set->res_y < 200)
		return (error_reso(1));
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i])
	{
		if (line[i] != ' ')
			return (error_reso(0));
		i++;
	}
	(*n)++;
	return (1);
}

int		test_directo(char *str)
{
	int fd;

	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (error_text("le config file (.cub).\n"
			"En effet c'est un dossier et non un fichier.\n", str));
	}
	close(fd);
	return (0);
}

int		search_line(t_param *set, int fd)
{
	int		n;
	int		k;
	int		l;
	char	**line;

	if (!(line = malloc(sizeof(char**))))
		return (error_param(2));
	n = 0;
	k = 1;
	l = 1;
	while (l == 1 && k == 1)
	{
		k = get_next_line(fd, line);
		if ((l = next_gnl(*line, &n, set)) == -1)
		{
			free(*line);
			free(line);
			return (-1);
		}
		free(*line);
	}
	free(line);
	return (0);
}
