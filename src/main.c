/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:00:03 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/08 15:28:06 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_param	*set;

	if (!(set = malloc(sizeof(t_param))))
		return (0);
	if (argc == 2)
		param_trim(argv[1], set);
	return (0);
}
