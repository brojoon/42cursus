/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:48:25 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/28 04:26:55 by hyungjki         ###   ########.fr       */
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
	int	i;
	int	sign;
	int	number;

	number = 0;
	sign = 1;
	while (is_blank(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number * sign);
}
