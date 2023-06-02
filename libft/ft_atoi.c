/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:30:56 by brmajor           #+#    #+#             */
/*   Updated: 2023/02/06 13:30:50 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(int i, int sign, const char *str)
{
	unsigned long int	result;
	int					count;

	result = 0;
	count = 0;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		result = (result * 10) + (str[i] - 48);
		count++;
		if ((result > ULONG_MAX || count > 19) && sign == -1)
			return (0);
		else if ((result > ULONG_MAX
				|| count > 19) && sign == 1)
			return (-1);
		i++;
	}
	return ((int)result);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	j = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	if (ft_isdigit(nptr[i]) == 1)
	{
		j = convert(i, sign, nptr);
		return (j * sign);
	}
	else
		return (0);
}
