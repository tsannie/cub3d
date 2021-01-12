/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:08:46 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/12 11:55:25 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_map(char *line, t_param *set)
{
	int	i;
	int not_blank;

	i = 0;
	not_blank = 0;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2'
		|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
		|| line[i] == 'Z' || line[i] == ' ')
		{
			not_blank++;
			i++;
		}
		else
			return (error_map());
	}
	if (not_blank >= 1)
	{
		if (!set->cpy)
			set->cpy = ft_strdup(line);
		else
			set->cpy = ft_strjoin(set->cpy, line);
		set->cpy = ft_strjoin(set->cpy, "\n");
		set->size_map++;
		return (1);
	}
	return (0);
}
