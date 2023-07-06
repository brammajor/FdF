/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:23:03 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/06 16:50:29 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	void	*mlx;
	void	*window;
	t_data	data;

	if (ac != 2)
		exit (1);
	error_check_width(av[1]);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		exit (1);
//	print_map(av[1]);
	read_map(av[1], fdf);

	data.window_x = 3500;
	data.window_y = 2000;
	mlx = mlx_init();
	window = mlx_new_window(mlx, data.window_x, data.window_y, "FdF");
	data.img = mlx_new_image(mlx, data.window_x, data.window_y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_len, &data.endian);

	data.zoom = 40;
	draw_map(fdf, &data);

	mlx_put_image_to_window(mlx, window, data.img, 0, 0);

	t_mlx	x;

	x.mlx = mlx;
	x.window = window;
	mlx_hook(window, 17, 0L, close_window, &x);
	mlx_key_hook(window, close_window_key, &x);
	mlx_loop(mlx);
}
