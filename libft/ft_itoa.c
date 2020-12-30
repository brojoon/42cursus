/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:54:42 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/31 07:22:41 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_th(int n)
{
	int		result;

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
	char	*result;
	int		len;

	len = len_th(n);
	result = (char *)malloc(len + 1);
	if (result)
	{
		if (n <= 0)
			*(result++) = (n == 0 ? '0' : '-');
		while (n)
		{
			*(result++) = n % 10 + '0';
			n /= 10;
		}
		*result = '\0';
	}
	return (result);
}
