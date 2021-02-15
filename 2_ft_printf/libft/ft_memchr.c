/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 02:23:12 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 07:56:43 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	void				*dst;

	dst = (void *)s;
	i = -1;
	while (++i < n)
	{
		if (*(unsigned char *)dst == (unsigned char)c)
			break ;
		dst++;
	}
	if (i == n)
		return (0);
	return (dst);
}
