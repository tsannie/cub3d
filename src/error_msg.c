/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:38:30 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/27 17:28:57 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		error_reso(char a)
{
	ft_putstr_fd("Error\nLa résolution enregistré n'est pas correcte.\n", 1);
	if (a == 1)
		ft_putstr_fd("Attention il faut minimum 200 de resolution pour"
		"une bonne exécution du jeu.\n", 1);
	if (a == 2)
		ft_putstr_fd("Attention il faut aue l'axe x soit au moins"
			"egal à l'axe y\n", 1);
	return (-1);
}

int		error_text(char *str, char *line)
{
	ft_putstr_fd("Error\nProblème sur le chemin vers ", 1);
	ft_putstr_fd(str, 1);
	if (line[ft_strlen(line) - 1] == ' ')
		ft_putstr_fd("Attention aux espaces en fin de ligne !\n", 1);
	return (-1);
}

int		error_param(void)
{
	ft_putstr_fd("Error\nIl y a des problèmes sur les paramètres de"
	" config.\n", 1);
	return (-1);
}

int		error_color(int a)
{
	ft_putstr_fd("Error\nProblème sur la couleur du ", 1);
	if (a == 1)
		ft_putstr_fd("sol (F)\n", 1);
	if (a == 2)
		ft_putstr_fd("plafond (C)\n", 1);
	ft_putstr_fd("Merci de relancer avec un format correct\n"
	"Exemple: \"C 220,100,20\"\n", 1);
	return (-1);
}

int		error_map(int a)
{
	ft_putstr_fd("Error\nProblème sur la map :\n", 1);
	if (a == 1)
		ft_putstr_fd("Plusieurs/Aucun point(s) de spawn détecté(s).\n", 1);
	if (a == 2)
		ft_putstr_fd("Caractère inconnu.\n", 1);
	if (a == 3)
		ft_putstr_fd("Le point de spawn n'est pas à l'intérieur.\n", 1);
	if (a == 4)
		ft_putstr_fd("Tout les '0' ne sont pas entourés.\n", 1);
	if (a == 5)
		ft_putstr_fd("Tout les '2' ne sont pas entourés.\n", 1);
	return (-1);
}
