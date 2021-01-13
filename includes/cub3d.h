/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:59:31 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/13 18:42:53 by tsannie          ###   ########.fr       */
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
#include <mlx.h>

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
	int			size_map_x;
	int			size_map_y;
	char		*cpy;
	char		pos;

	void		*mlx;
	void		*win;

	float		resm_x;
	float		resm_y;
	float		start_x;
	float		start_y;
	float		end_x;
	float		end_y;
	float		size_cub;
	float 		s_x;
	float		s_y;
	float		e_x;
	float		e_y;
	float		pps_x;
	float		pps_y;
	float		ppe_x;
	float		ppe_y;

	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_param;

int		param_trim(char *str, t_param *set);
int		next_gnl(char *str, int *n, t_param *set);
int		trim_reso(char *line, int *n, t_param *set);
int		clr_ground(char *line, int *n, t_param *set);
int		clr_ceiling(char *line, int *n, t_param *set);
int		trim_textno(char *line, int *n, t_param *set);
int		trim_textso(char *line, int *n, t_param *set);
int		trim_textwe(char *line, int *n, t_param *set);
int		trim_textea(char *line, int *n, t_param *set);
int		trim_texts(char *line, int *n, t_param *set);
int		check_open(char *str);
int		trim_map(char *line, t_param *set);

int		error_reso(void);
int		error_param(void);
int		error_text(char *str, char *line);
int		error_color(int a);
int		error_map(int a);

void	print_struct(t_param *set);
void	print_map(t_param *set);

int		check_map(t_param *set);
int		logic_map(t_param *set);

int		start_cub(t_param *set);

int		create_color(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_param *set, int x, int y, int color);
int		*create_coord(int cord[4], int x_start, int y_start, int x_end, int y_end);
void	print_square(t_param *set, int *cord, int color);
void	print_minimap(t_param *set, int a);
void	map_in_minimap(t_param *set, int a);
int		moove_player(int keycode, t_param *set);
void	change_pos(t_param *set, int a);

#endif
