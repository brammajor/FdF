/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:23:03 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/08 13:59:15 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"


int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		exit (1);
	fd = open(av[1], O_RDONLY);
	

/*	void	*mlx;
	void	*window;
	t_data	d;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "FdF");
	d.img = mlx_new_image(mlx, 1920, 1080);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_len, &d.endian);
	draw_line((t_pixel){100, 200, 0x0000FF00}, (t_pixel){400, 300}, &d);
	mlx_put_image_to_window(mlx, window, d.img, 0, 0);
	mlx_loop(mlx);
*/
}
