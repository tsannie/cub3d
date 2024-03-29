/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:14:47 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 02:00:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		correct_name(char *str)
{
	if ((str[ft_strlen(str) - 1] != 'b'
	|| str[ft_strlen(str) - 2] != 'u' || str[ft_strlen(str) - 3] != 'c'
	|| str[ft_strlen(str) - 4] != '.'))
		return (0);
	return (1);
}

int		is_object(char a)
{
	if (a == '0' || a == '1' || a == '2'
		|| a == 'N' || a == 'S' || a == 'E'
		|| a == 'W' || a == ' ')
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
	set->cpy = ft_strjoin_free(set->cpy, line);
	set->cpy = ft_strjoin_free(set->cpy, "\n");
	set->size_map_x++;
	return (1);
}

int		next2_gnl(char *str, int *n, t_param *set, int i)
{
	if (str[i] == 'S')
		return (trim_texts(&str[i], n, set));
	else if (str[i] == 'F')
		return (clr_ground(&str[i], n, set));
	else if (str[i] == 'C')
		return (clr_ceiling(&str[i], n, set));
	else if (*n == 8)
		return (trim_map(str, set));
	else if (str[i] != ' ')
		return (error_param(1));
	else if (*n > 8)
		return (error_param(3));
	return (-2);
}

int		next_gnl(char *str, int *n, t_param *set)
{
	int i;
	int ret;

	i = 0;
	while (str[i] || (str[0] == '\0' && *n == 8 && set->size_map_x != 0))
	{
		if (str[i] == 'R')
			return (trim_reso(&str[i], n, set));
		else if (str[i] == 'N' && str[i + 1] == 'O')
			return (trim_textno(&str[i], n, set));
		else if (str[i] == 'S' && str[i + 1] == 'O')
			return (trim_textso(&str[i], n, set));
		else if (str[i] == 'W' && str[i + 1] == 'E')
			return (trim_textwe(&str[i], n, set));
		else if (str[i] == 'E' && str[i + 1] == 'A')
			return (trim_textea(&str[i], n, set));
		else
			ret = next2_gnl(str, n, set, i);
		if (ret != -2)
			return (ret);
		i++;
	}
	return (1);
}
