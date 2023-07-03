/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:11:15 by brmajor           #+#    #+#             */
/*   Updated: 2023/07/03 12:26:57 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	get_height(char *file_name)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(file_name, O_RDONLY);
	y = -1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	return (y);
}

int	get_width(char *file_name)
{
	int		fd;
	int		x;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	x = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (x);
}

void	fill_matrix(int *i_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
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

	fdf->y = get_height(file_name);
	fdf->x = get_width(file_name);
	fdf->matrix = (int **)malloc(sizeof(int *) * (fdf->y + 1));
	i = 0;
	while (i <= fdf->y)
		fdf->matrix[i++] = (int *)malloc(sizeof(int) * (fdf->x));
	fd = open(file_name, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(fdf->matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	fdf->matrix[i] = NULL;
}
