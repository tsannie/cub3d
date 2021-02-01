/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:08:46 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 12:24:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		most_long(t_param *set)
{
	int		ml;
	int		i;

	i = 0;
	ml = 0;
	while (set->map[i])
	{
		if (ft_strlen(set->map[i]) > (size_t)ml)
			ml = ft_strlen(set->map[i]);
		i++;
	}
	set->size_map_y = ml;
	return (ml);
}

char	*rebuild_line(char *str, int ml)
{
	char	*res;
	int		i;

	if (!(res = malloc(sizeof(char *) * ml + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (ml > i)
	{
		res[i] = ' ';
		i++;
	}
	res[ml] = '\0';
	free(str);
	return (res);
}

void	fill_map(t_param *set)
{
	int		ml;
	int		i;

	ml = most_long(set);
	i = 0;
	while (set->map[i])
	{
		if (ft_strlen(set->map[i]) < (size_t)ml)
		{
			set->map[i] = rebuild_line(set->map[i], ml);
		}
		i++;
	}
}

int		one_spawn(t_param *set)
{
	int		i;
	int		e;
	int		glob;

	i = 0;
	glob = 0;
	while (set->map[i])
	{
		e = 0;
		while (set->map[i][e])
		{
			if (set->map[i][e] == 'N' || set->map[i][e] == 'S'
			|| set->map[i][e] == 'E' || set->map[i][e] == 'W')
			{
				set->pos = set->map[i][e];
				glob++;
			}
			e++;
		}
		i++;
	}
	if (glob != 1)
		return (error_map(1));
	return (0);
}

int		check_map(t_param *set)
{
	if (there_is_map(set) == -1)
		return (-1);
	fill_map(set);
	if (one_spawn(set) == -1)
		return (-1);
	if (logic_map(set) == -1)
		return (-1);
	return (0);
}
