/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:57:08 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/08 15:39:19 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	trim_reso(char *line, t_param *set)
{
	int		n;
	int		i;
	int		e;
	char	*nbr;

	n = 0;
	i = 0;
	while (n++ <= 1)
	{
		nbr = malloc(sizeof(char) * 10);
		e = 0;
		while (ft_isdigit(line[i]) == 0)
			i++;
		while (ft_isdigit(line[i]) == 1)
		{
			nbr[e] = line[i];
			e++;
			i++;
		}
		if (n == 1)
			set->res_x = ft_atoi(nbr);
		else
			set->res_y = ft_atoi(nbr);
		free(nbr);
	}
}

void	param_trim(char *str, t_param *set)
{
	int		fd;
	char	**line;

	line = malloc(sizeof(char**));
	fd = open(str, O_RDONLY);
	get_next_line(fd, line);
	if (*line[0] == 'R')
	{
		trim_reso(*line, set);
		printf("%d\n", set->res_x);
		printf("%d\n", set->res_y);
	}
	free(line);
}
