/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:53:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/11 18:06:37 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		trim_textno(char *line, int *n, t_param *set)
{
	int		i;

	i = 2;
	while (line[i] == ' ')
		i++;
	set->text_no = ft_strdup(&line[i]);
	if (!(set->text_no) || check_open(set->text_no) == -1)
		return (error_text("texture nord (NO).\n", line));
	else
	{
		(*n)++;
		return (1);
	}
}

int		trim_textso(char *line, int *n, t_param *set)
{
	int		i;

	i = 2;
	while (line[i] == ' ')
		i++;
	set->text_so = ft_strdup(&line[i]);
	if (!(set->text_so) || check_open(set->text_so) == -1)
		return (error_text("texture sud (SO).\n", line));
	else
	{
		(*n)++;
		return (1);
	}
}

int		trim_textwe(char *line, int *n, t_param *set)
{
	int		i;

	i = 2;
	while (line[i] == ' ')
		i++;
	set->text_we = ft_strdup(&line[i]);
	if (!(set->text_we) || check_open(set->text_we) == -1)
		return (error_text("texture ouest (WE).\n", line));
	else
	{
		(*n)++;
		return (1);
	}
}

int		trim_textea(char *line, int *n, t_param *set)
{
	int		i;

	i = 2;
	while (line[i] == ' ')
		i++;
	set->text_ea = ft_strdup(&line[i]);
	if (!(set->text_ea) || check_open(set->text_ea) == -1)
		return (error_text("texture est (EA).\n", line));
	else
	{
		(*n)++;
		return (1);
	}
}

int		trim_texts(char *line, int *n, t_param *set)
{
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	set->text_s = ft_strdup(&line[i]);
	if (!(set->text_s) || check_open(set->text_s) == -1)
		return (error_text("texture sprite (S).\n", line));
	else
	{
		(*n)++;
		return (1);
	}
}
