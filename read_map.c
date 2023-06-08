/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:11:15 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/08 12:34:10 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	**make_table(int fd)
{
	char	**str;
	int	i;

	i = 0;
	while (get_next_line(fd))
	{
		str[i] = get_next_line(fd);
	}
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}
