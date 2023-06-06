/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:54:50 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/06 13:51:27 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	get_height(char *file_name)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line))i
	{
		y++;
		free(line);
	}
	close (fd);
	return (y);
}

int	get_width(char *file_name)
{
	int		fd;
	int		x;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	x = 0;
	get_next_line(fd, &line);
	x = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (x);
}

void	read_file()
{
	
}
