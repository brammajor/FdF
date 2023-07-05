/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:13:29 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/05 16:44:17 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line_bonus.h"
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_draw
{
	int	absx;
	int	absy;
	int	relx;
	int	rely;
	int	err;
	int	e2;
}		t_draw;

typedef struct	s_vec
{
	int	x;
	int	y;
}		t_vec;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	color;
	int	z;

}		t_pixel;

typedef	struct	s_fdf
{
	int	x;
	int	y;
	int	**matrix;
}		t_fdf;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		zoom;
	int		color;
}			t_data;

t_draw	*init_draw(t_pixel p1, t_pixel p2, t_data *data);
void	my_mlx_pixel_put(t_data *data, t_pixel p);
void	draw_line(t_pixel p1, t_pixel p2, t_data *data, t_fdf *fdf);

void	read_map(char *file_name, t_fdf *fdf);
void	fill_matrix(int *i_line, char *line);
void	get_dimensions(char *file_name, t_fdf *fdf);

void	error_check_width(char *file_name);
int		count_spaces(char *line);

void	print_map(char *file_name);

void	free_array(int **arr, int len);

void	draw_map(t_fdf *fdf, t_data *data);

#endif

