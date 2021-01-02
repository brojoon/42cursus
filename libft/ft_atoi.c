/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:48:25 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 21:17:39 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_blank(char a)
{
	return (a == '\t' || a == '\v' || a == '\f' \
	|| a == '\r' || a == '\n' || a == ' ');
}

int			ft_atoi(const char *str)
{
	long long		number;
	unsigned char	*ptr;
	long long		sign;

	number = 0;
	sign = 1;
	ptr = (unsigned char *)str;
	while (is_blank(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
		sign *= (*ptr++ == '-') ? -1 : 1;
	while (*ptr >= '0' && *ptr <= '9')
		number = number * 10 + *ptr++ - '0';
	return (number * sign);
}
