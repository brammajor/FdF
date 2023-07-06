/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:36:59 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/06 16:38:27 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_pixel	project_2d(t_pixel p, t_fdf *fdf)
{
	t_pixel	new_p;

	new_p.x = (p.x - p.y) * cos(0.5);
	new_p.y = (p.x + p.y) * sin(0.5) - p.z;
	return (new_p);
}

t_draw	*init_draw(t_pixel p1, t_pixel p2, t_data *data)
{
	t_draw	*draw;

	draw = (t_draw *)malloc(sizeof(t_draw));
	if (!draw)
		exit (1);
	draw->absx = abs(p2.x - p1.x);
	draw->absy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
        draw->relx = 1;
    else
        draw->relx = -1;
    if (p1.y < p2.y)
        draw->rely = 1;
    else
        draw->rely = -1;
	draw->err = draw->absx - draw->absy;
	return (draw);
}

void	my_mlx_pixel_put(t_data *data, t_pixel p)
{
	char	*dst;

	p.color = 0x0000FF00;
	if (p.z > 0)
		p.color = 0xFFFF0000;
	dst = data->addr + ((p.y + 200) * data->line_len + (p.x + 1500) * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = p.color;
}

void	draw_line(t_pixel p1, t_pixel p2, t_data *data, t_fdf *fdf)
{
	t_draw	*draw;
	t_pixel	iso_p1;
	t_pixel	iso_p2;

	p1.z = fdf->matrix[p1.y][p1.x];
	p2.z = fdf->matrix[p2.y][p2.x];

	p1.x *= data->zoom;
	p1.y *= data->zoom;
	p2.x *= data->zoom;
	p2.y *= data->zoom;

	iso_p1 = project_2d(p1, fdf);
	iso_p2 = project_2d(p2, fdf);
	iso_p1.z = p1.z;
	iso_p2.z = p2.z;

	draw = init_draw(iso_p1, iso_p2, data);

	while (iso_p1.x != iso_p2.x || iso_p1.y != iso_p2.y)
	{
		my_mlx_pixel_put(data, iso_p1);
		draw->e2 = 2 * draw->err;
		if (draw->e2 > -draw->absy)
		{
			draw->err -= draw->absy;
			iso_p1.x += draw->relx;
		}
		if (draw->e2 < draw->absx)
		{
			draw->err += draw->absx;
			iso_p1.y += draw->rely;
		}
	}
}
