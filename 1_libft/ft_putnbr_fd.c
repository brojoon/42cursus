/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:01:17 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 08:27:45 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	long long	number;
	char		buf[19];
	int			idx;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	number = (long long)n;
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
