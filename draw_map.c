/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:32:39 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/04 18:33:23 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw_map(t_fdf *fdf, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= fdf->y)
	{
		x = 0;
		while (x <= fdf->x)
		{
			if (y < fdf->y)
				draw_line((t_pixel){x, y}, (t_pixel){x, y + 1}, data, fdf);
			if (x < fdf->x)
				draw_line((t_pixel){x, y}, (t_pixel){x + 1, y}, data, fdf);
			x++;
		}
		y++;
	}
}
