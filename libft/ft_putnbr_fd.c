/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:01:27 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 04:03:13 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	long long	number;
	char		buf[19];
	size_t		idx;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	number = n;
	idx = 0;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	while (number)
	{
		buf[idx++] = number % 10 + '0';
		number /= 10;
	}
	while (--idx >= 0)
		write(fd, buf + idx, 1);
}
