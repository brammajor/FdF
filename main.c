/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:23:03 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/26 12:37:22 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"


int	main(int ac, char **av)
{
	int		fd;
	char	*file_name;
	t_fdf	*data;

	if (ac != 2)
		exit (1);
	file_name = av[1];
	data = (t_fdf *)malloc(sizeof(t_fdf));
	fd = open(file_name, O_RDONLY);
	if (!fd)
		exit (1);
	read_map(file_name, data);

	int	i;
	int	j = 0;

	while (data->matrix[j])
	{
		i = 0;
		while (data->matrix[j][i])
		{
			ft_printf("%3i", data->matrix[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
	close(fd);
}
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

