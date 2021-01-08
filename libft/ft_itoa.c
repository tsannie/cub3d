/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:24:08 by tsannie           #+#    #+#             */
/*   Updated: 2020/10/14 16:44:06 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_int(int n)
{
	int i;
	int cpy;

	cpy = n;
	i = 1;
	if (cpy < 0)
	{
		i++;
		cpy = cpy * -1;
	}
	while (cpy)
	{
		cpy = cpy / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		neg;
	int		i;

	if (n == I_MIN || n == 0)
		return ((n != 0) ? ft_strdup("-2147483648") : ft_strdup("0"));
	if (!(res = malloc(sizeof(char) * size_int(n))))
		return (NULL);
	neg = 0;
	if (n < 0)
	{
		res[0] = '-';
		neg = 1;
		n = n * -1;
	}
	i = (neg == 1) ? 1 : 0;
	while (n)
	{
		res[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	res[i] = '\0';
	(neg == 1) ? ft_rev_char_tab(&res[1]) : ft_rev_char_tab(res);
	return (res);
}
