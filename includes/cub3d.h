/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:59:31 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/11 18:37:07 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# include <stdio.h>

typedef struct	s_param{
	int			res_x;
	int			res_y;

	char		*text_no;
	char		*text_so;
	char		*text_we;
	char		*text_ea;
	char		*text_s;

	int			f_r;
	int			f_g;
	int			f_b;

	int			c_r;
	int			c_g;
	int			c_b;

	char		**map; 
}				t_param;

int		param_trim(char *str, t_param *set);
int		trim_textno(char *line, int *n, t_param *set);
int		trim_textso(char *line, int *n, t_param *set);
int		trim_textwe(char *line, int *n, t_param *set);
int		trim_textea(char *line, int *n, t_param *set);
int		trim_texts(char *line, int *n, t_param *set);
int		check_open(char *str);

int		error_reso(void);
int		error_param(void);
int		error_text(char *str, char *line);
int		error_color(int a);

void	print_struct(t_param *set);

#endif