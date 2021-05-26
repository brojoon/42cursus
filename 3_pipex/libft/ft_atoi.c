/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:48:24 by hyungjki          #+#    #+#             */
/*   Updated: 2021/05/24 13:34:42 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_blank(char a)
{
	return (a == '\t' || a == '\v' || a == '\f' \
	|| a == '\r' || a == '\n' || a == ' ');
}

int			ft_atoi(const char *str)
{
	int				number;
	unsigned char	*ptr;
	int				sign;
	int				i;

	number = 0;
	sign = 1;
	i = 0;
	ptr = (unsigned char *)str;
	while (is_blank(ptr[i]))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
		number = number * 10 + ptr[i++] - '0';
	return (number * sign);
}
