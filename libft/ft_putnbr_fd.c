/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:01:27 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/31 07:22:24 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	dfs(int n, int fd)
{
	char c;

	c = n % 10 + '0';
	if (n > 9)
		dfs(n / 10, fd);
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	char c;

	if (n < 0)
	{
		write(fd, "-", 1);
		dfs(n / -10, fd);
		c = n % -10 + '0';
		write(fd, &c, 1);
	}
	else
		dfs(n, fd);
}
