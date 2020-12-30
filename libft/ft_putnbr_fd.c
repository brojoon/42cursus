/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:01:27 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/30 07:49:17 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	dfs(int n, int fd)
{
	char buf[1];

	buf[0] = n % 10 + '0';
	if (n > 9)
		dfs(n / 10, fd);
	write(fd, buf, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	char	buf[1];

	if (n < 0)
	{
		write(fd, "-", 1);
		dfs(n / -10, fd);
		buf[0] = n % 10 + '0';
		write(fd, buf, 1);
	}
	else
		dfs(n, fd);
}
