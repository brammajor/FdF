/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:29:37 by brmajor           #+#    #+#             */
/*   Updated: 2023/03/17 12:29:57 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*get_line(char *str, char c);
char	*get_rest_of_line(char *str, char c);
char	*ft_strjoin(char *dest, char *src);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);

#endif
