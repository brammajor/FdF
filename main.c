/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:23:03 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/05 16:49:00 by brmajor          ###   ########.fr       */
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

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "FdF");
	data.img = mlx_new_image(mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_len, &data.endian);
	data.zoom = 60;
	draw_map(fdf, &data);
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);
	mlx_loop(mlx);
	free(fdf->matrix);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
}
