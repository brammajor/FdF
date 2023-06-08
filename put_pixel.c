/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:06:46 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/07 15:52:53 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	my_mlx_pixel_put(t_data *d, t_pixel p)
{
	char	*dst;

	dst = d->addr + (p.y * d->line_len + p.x * (d->bits_per_pixel / 8));
	*(unsigned int*)dst = p.color;
}


