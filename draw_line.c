/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:36:59 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/03 12:23:18 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_mlx_pixel_put(t_data *data, t_pixel p)
{
	char	*dst;

	dst = data->addr + (p.y * data->line_len + p.x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = p.color;
}

void	draw_line(t_pixel p1, t_pixel p2, t_data *data)
{
	int	dx = abs(p2.x - p1.x);
	int	dy = abs(p2.y - p1.y);
	int	sx = (p1.x < p2.x) ? 1 : -1;
	int	sy = (p1.y < p2.y) ? 1 : -1;
	int	err = dx - dy;

	while (p1.x != p2.x || p1.y != p2.y)
	{
		my_mlx_pixel_put(data, p1);
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			p1.y += sy;
		}
	}
}
