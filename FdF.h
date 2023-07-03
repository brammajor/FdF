/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:13:29 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/03 12:08:42 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

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
}			t_data;

void	my_mlx_pixel_put(t_data *d, t_pixel p);
void	draw_line(t_pixel p1, t_pixel p2, t_data *d);
char	**make_table(int fd);

void	read_map(char *file_name, t_fdf *data);
void	fill_matrix(int *i_line, char *line);
int		get_width(char *file_name);
int		get_height(char *file_name);

void	error_check_width(char *file_name);
int		count_spaces(char *line);

void	print_map(char *file_name);

#endif

