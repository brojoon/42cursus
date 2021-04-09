/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:48:24 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/03 22:28:45 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_blank(char a)
{
	return (a == '\t' || a == '\v' || a == '\f' \
	|| a == '\r' || a == '\n' || a == ' ');
}

int	ft_atoi(const char *str)
{
	int				number;
	unsigned char	*ptr;
	int				sign;

	number = 0;
	sign = 1;
	ptr = (unsigned char *)str;
	while (is_blank(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
		number = number * 10 + *ptr++ - '0';
	return (number * sign);
}
