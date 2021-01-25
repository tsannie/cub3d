/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:01:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/25 17:19:43 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float		speed_moove(t_param *set)
{
	float speed;

	speed = set->size_cub / 5;
	return (speed);
}

int		create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_param *set, int x, int y, int color)
{
	char	*dst;

	dst = set->addr + (y * set->line_length + x * (set->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		*create_coord(int x_start, int y_start, int x_end, int y_end)
{
	int *cord;

	if (!(cord = malloc(sizeof(int) * 4)))
		return (0);
	cord[0] = x_start;
	cord[1] = y_start;
	cord[2] = x_end;
	cord[3] = y_end;
	return (cord);
}

void	middle_point(t_param *set)
{
	float cote;
	float e;

	cote = set->ppe_y - set->pps_y;
	e = cote / 2;
	set->perso_x = set->pps_x + e;
	set->perso_y = set->pps_y + e;
}

float	exter_point(t_param *set, float value, int a)
{
	float cote;
	float e;

	cote = set->ppe_y - set->pps_y;
	e = cote / 2;
	if (a == 1)
		return (value - e);
	if (a == 2)
		return (value+ e);
	if (a == 3)
		return (value - e);
	if (a == 4)
		return (value + e);
	return (0);
}

void	 print_square(t_param *set, int *cord, int color)
{
	int i;
	int e;

	i = cord[0];
	while (i < cord[2])
	{
		e = cord[1];
		while (e < cord[3])
		{
			my_mlx_pixel_put(set, i, e, color);
			e++;
		}
		i++;
	}
}

void	set_orient(t_param *set)
{
	if (set->pos == 'S')
		set->orient_p = M_PI_2;
	if (set->pos == 'N')
		set->orient_p = -(M_PI/2);
	if (set->pos == 'E')
		set->orient_p = 0;
	if (set->pos == 'W')
		set->orient_p = M_PI;
}

void	assign_text(t_param *set)
{
	int i;

	i = 1;
	if ((set->imgS = mlx_xpm_file_to_image(set->mlx, set->text_so, &i, &i)) == NULL)
		printf("MAL INIT\n");
	set->addrS = mlx_get_data_addr(set->imgS, &set->bits_per_pixelS, &set->line_lengthS, &set->endianS);

	if ((set->imgN = mlx_xpm_file_to_image(set->mlx, set->text_no, &i, &i)) == NULL)
		printf("MAL INIT\n");
	set->addrN = mlx_get_data_addr(set->imgN, &set->bits_per_pixelN, &set->line_lengthN, &set->endianN);

	if ((set->imgE = mlx_xpm_file_to_image(set->mlx, set->text_ea, &i, &i)) == NULL)
		printf("MAL INIT\n");
	set->addrE = mlx_get_data_addr(set->imgE, &set->bits_per_pixelE, &set->line_lengthE, &set->endianE);

	if ((set->imgW = mlx_xpm_file_to_image(set->mlx, set->text_we, &i, &i)) == NULL)
		printf("MAL INIT\n");
	set->addrW = mlx_get_data_addr(set->imgW, &set->bits_per_pixelW, &set->line_lengthW, &set->endianW);
}

float	search_wall(t_param *set)
{
	float lgr;

	lgr = 0;
	set->dx = cos(set->angle);
	set->dy = sin(set->angle);
	set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
	set->e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
	while (set->map[(int)set->e][(int)set->i] != '1' && set->map[(int)set->e][(int)set->i] != ' ' && set->map[(int)set->e][(int)set->i] != '4' && set->map[(int)set->e][(int)set->i] != '5')
	{
		//printf("lgr = %f | set->map[e][i] = |%c|\n", lgr, set->map[(int)set->e][(int)set->i]);
		lgr += speed_moove(set);
		set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
		set->e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
		//my_mlx_pixel_put(set, i * set->size_cub + set->start_size, e * set->size_cub + set->start_size, create_color(0, 176, 0, 144));
	}
	if (set->map[(int)set->e][(int)set->i] == '1')
	{
		set->xspe = 0;
		set->map[(int)set->e][(int)set->i] = '4';
	}
	else if (set->map[(int)set->e][(int)set->i] == ' ')
	{
		set->xspe = 0;
		set->map[(int)set->e][(int)set->i] = '5';
	}
	lgr -= speed_moove(set);
	set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
	set->e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
	while (set->map[(int)set->e][(int)set->i] != '4' && set->map[(int)set->e][(int)set->i] != '5')
	{
		lgr += speed_moove(set) / 250;
		set->i = ((set->perso_x + ((set->dx * lgr))) - set->start_size) / set->size_cub;
		set->e = ((set->perso_y + ((set->dy * lgr))) - set->start_size) / set->size_cub;
		//my_mlx_pixel_put(set, i * set->size_cub + set->start_size, e * set->size_cub + set->start_size, create_color(0, 176, 0, 144));
	}
	//printf("\n\nBefore:\ne = %f | i = %f | set->map[e][i] = |%c|\nlgr = %f\n",set->e,set->i, set->map[(int)set->e][(int)set->i], lgr);
	return (lgr);
}

void 	wash_map(t_param *set)
{
	int		i;
	int		e;

	i = 0;
	while (set->map[i])
	{
		e = 0;
		while (set->map[i][e])
		{
			if (set->map[i][e] == '4')
				set->map[i][e] = '1';
			else if (set->map[i][e] == '5')
				set->map[i][e] = ' ';
			e++;
		}
		i++;
	}
}