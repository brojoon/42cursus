/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:01:17 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/20 06:38:54 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(unsigned int n, int fd)
{
	char			buf[19];
	int				idx;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	idx = 0;
	while (n)
	{
		buf[idx++] = n % 10 + '0';
		n /= 10;
	}
	while (--idx >= 0)
		write(fd, buf + idx, 1);
}
