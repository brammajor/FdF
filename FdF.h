/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:13:29 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/19 10:20:33 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef	struct	s_fdf
{
	int	x;
	int	y;
	int	**matrix;
}	t_fdf;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *d, t_pixel p);
void	draw_line(t_pixel p1, t_pixel p2, t_data *d);

#endif

