/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:37:43 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/06 17:21:00 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	close_window(t_mlx *x, int keycode)
{
	mlx_destroy_window(x->mlx, x->window);
	mlx_destroy_display(x->mlx);
	free(x->mlx);
	exit (0);
}

int	close_window_key(int keycode, t_mlx *x)
{
	ft_printf("%i", keycode);
	if (keycode == 65307)
		close_window(x, keycode);
	return (0);
}
