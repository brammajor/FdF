/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:19:18 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/06 13:50:21 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx-linux.tgz"

typedef	struct	s_fdf
{
	int	x;
	int	y;
	int	**matrix;
}	t_fdf;

#endif
