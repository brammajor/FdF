/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:11:15 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/03 18:30:17 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"


void	get_dimensions(char *file_name, t_fdf *fdf)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(file_name, O_RDONLY);
	y = -1;
	line = get_next_line(fd);
	fdf->x = ft_count_words(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	fdf->y = y;
}

void	fill_matrix(int *i_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i] != NULL)
	{
		i_line[i] = ft_atoi(nums[i]);
		free(nums[i++]);
	}
	free(nums);
}

void	read_map(char *file_name, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;

	get_dimensions(file_name, fdf);
	fdf->matrix = (int **)malloc(sizeof(int *) * (fdf->y + 1));
	if (!fdf->matrix)
		exit (1);
	i = 0;
	while (i <= fdf->y)
		fdf->matrix[i++] = (int *)malloc(sizeof(int) * (fdf->x));
	fd = open(file_name, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line[ft_strlen(line) - 1] = '\0';
		fill_matrix(fdf->matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
