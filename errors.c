/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:41:15 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/30 16:31:11 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	count_spaces(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			count++;
			while (line[i] == ' ')
				i++;
		}
		i++;
	}
	return (count);
}

void	error_check_width(char *file_name)
{
	int		fd;
	int		x;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (!fd)
		exit (1);
	line = get_next_line(fd);
	x = count_spaces(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			i = count_spaces(line);
		if (i != x)
			exit (1);
	}
	free(line);
	close(fd);
}
