/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:14:47 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/12 18:05:45 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_object(char a)
{
	if (a == '0' || a == '1' || a == '2'
		|| a == 'N' || a == 'S' || a == 'E'
		|| a == 'Z' || a == ' ')
		return (1);
	return (0);
}

int		trim_map(char *line, t_param *set)
{
	int	i;

	i = 0;
	if (*line == '\0')
	{
		free(line);
		line = ft_strdup(" ");
	}
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i])
	{
		if (is_object(line[i]) == 1)
			i++;
		else
			return (error_map(2));
	}
	if (!set->cpy)
		set->cpy = ft_strdup(line);
	else
		set->cpy = ft_strjoin(set->cpy, line);
	set->cpy = ft_strjoin(set->cpy, "\n");
	set->size_map++;
	return (1);
}

int		next2_gnl(char *str, int *n, t_param *set, int i)
{
	if (str[i] == 'S' && *n == 5)
		return (trim_texts(&str[i], n, set));
	if (str[i] == 'F' && *n == 6)
		return (clr_ground(&str[i], n, set));
	if (str[i] == 'C' && *n == 7)
		return (clr_ceiling(&str[i], n, set));
	if (*n == 8)
		return (trim_map(str, set));
	if (str[i] != ' ')
		return (error_param());
	return (-2);
}

int		next_gnl(char *str, int *n, t_param *set)
{
	int i;
	int ret;

	i = 0;
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
		ret = next2_gnl(str, n, set, i);
		if (ret != -2)
			return (ret);
		i++;
	}
	return (1);
}
