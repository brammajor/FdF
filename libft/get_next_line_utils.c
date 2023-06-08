/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:00:16 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/24 13:05:20 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*u;
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	u = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!u)
		return (NULL);
	while (s1[++i])
		u[i] = s1[i];
	while (s2[j])
		u[i++] = s2[j++];
	u[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (u);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_rest_of_line(char *str, char c)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != c && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = malloc(ft_strlen(str) - i + 1);
	if (!new)
		return (NULL);
	i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*get_line(char *str, char c)
{
	char	*new;
	int		i;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
		i++;
	new = malloc(i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == c)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
