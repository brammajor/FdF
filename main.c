/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:23:03 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/30 16:35:02 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"


int	main(int ac, char **av)
{
	t_fdf	*data;
	void	*mlx;
	void	*window;
	t_data	d;

	if (ac != 2)
		exit (1);
	error_check_width(av[1]);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	print_map(av[1]);
	read_map(av[1], data);

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "FdF");
	d.img = mlx_new_image(mlx, 1920, 1080);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_len, &d.endian);
	draw_line((t_pixel){10, 20, 0x0000FF00}, (t_pixel){1400, 800}, &d);
	mlx_put_image_to_window(mlx, window, d.img, 0, 0);
	mlx_loop(mlx);
}
