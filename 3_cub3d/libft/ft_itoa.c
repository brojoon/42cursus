/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:54:44 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 06:40:01 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_th(long long n)
{
	long long	result;

	result = ((n <= 0) ? 1 : 0);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char		*ft_itoa(int n)
{
	char		*result;
	long long	numbers;
	long long	len;

	result = (char *)malloc(len_th(n) + 1);
	if (result)
	{
		len = len_th(n);
		result[len--] = '\0';
		if (n <= 0)
			result[0] = (n == 0) ? '0' : '-';
		numbers = n < 0 ? -(long long)n : (long long)n;
		while (numbers)
		{
			result[len--] = numbers % 10 + '0';
			numbers /= 10;
		}
	}
	return (result);
}
