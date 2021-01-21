/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:05:49 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/21 16:02:15 by tsannie          ###   ########.fr       */
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
