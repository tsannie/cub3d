/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:59:31 by tsannie           #+#    #+#             */
/*   Updated: 2021/02/01 11:24:41 by user42           ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"
# include <math.h>

# include <stdio.h>

typedef struct	s_param{
	int			screenx;
	int			screeny;
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

	float		resm_size;
	float		start_size;
	float		end_size;
	float		size_cub;
	float		s_x;
	float		s_y;
	float		e_x;
	float		e_y;
	float		pps_x;
	float		pps_y;
	float		ppe_x;
	float		ppe_y;
	float		perso_x;
	float		perso_y;
	float		orient_p;
	int			i_line;
	float		dx;
	float		dy;
	float		i;
	float		e;
	float		angle;
	float		xspe;
	float		yspe;
	float		pre_wall;
	float		lgr;

	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	void		*imgn;
	char		*addrn;
	int			bits_per_pixeln;
	int			line_lengthn;
	int			endiann;

	void		*imgs;
	char		*addrs;
	int			bits_per_pixels;
	int			line_lengths;
	int			endians;

	void		*imge;
	char		*addre;
	int			bits_per_pixele;
	int			line_lengthe;
	int			endiane;

	void		*imgw;
	char		*addrw;
	int			bits_per_pixelw;
	int			line_lengthw;
	int			endianw;

	void		*imgsp;
	char		*addrsp;
	int			bits_per_pixelsp;
	int			line_lengthsp;
	int			endiansp;

	int			t_r;
	int			t_g;
	int			t_b;

	float		lgr_spr;
	int			sprite;
	float		xspe_spr;
	float		htr;
	int			spr_pres;

	int			save;
}				t_param;

int				param_trim(char *str, t_param *set);
int				correct_name(char *str);
int				next_gnl(char *str, int *n, t_param *set);
int				trim_reso(char *line, int *n, t_param *set);
int				clr_ground(char *line, int *n, t_param *set);
int				clr_ceiling(char *line, int *n, t_param *set);
int				trim_textno(char *line, int *n, t_param *set);
int				trim_textso(char *line, int *n, t_param *set);
int				trim_textwe(char *line, int *n, t_param *set);
int				trim_textea(char *line, int *n, t_param *set);
int				trim_texts(char *line, int *n, t_param *set);
int				check_open(char *str);
int				test_directo(char *str);
int				search_line(t_param *set, int fd);
int				trim_map(char *line, t_param *set);
int				all_text(t_param *set);

int				error_reso(char a);
int				error_param(char a);
int				error_text(char *str, char *line);
int				error_color(int a);
int				error_map(int a);

int				print_line(t_param *set);

int				check_map(t_param *set);
int				logic_map(t_param *set);

int				start_cub(t_param *set);

float			exter_point(t_param *set, float value, int a);
void			set_orient(t_param *set);
void			middle_point(t_param *set);
void			my_mlx_pixel_put(t_param *set, int x, int y, int color);
int				*create_coord(int x_start, int y_start, int x_end, int y_end);
void			print_square(t_param *set, int *cord, int color);
int				minimap(t_param *set, int a);
void			map_in_minimap(t_param *set, int a);
int				moove_player(int keycode, t_param *set);
void			colision(t_param *set, int a);
float			speed_moove(t_param *set);
int				exit_win(int keycode, t_param *set);
int				assign_text(t_param *set);
float			search_wall(t_param *set);
void			wash_map(t_param *set);
void			re_alloc(t_param *set);
void			save_pos(t_param *set);
void			align_text(t_param *set);
void			pres_sprite(t_param *set);

int				leave_hook(t_param *set);
void			free_struct(t_param *set);

void			print_ground(t_param *set, int a, int *cord);
int				create_color(int r, int g, int b);
int				print_spite(t_param *set);
int				bit_map(t_param *set);

#endif
