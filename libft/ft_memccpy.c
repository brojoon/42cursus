/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 05:20:09 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/31 04:29:03 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	idx;

	if (!dst || !src)
		return (dst);
	idx = 0;
	while (idx < n)
	{
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		if (((unsigned char *)dst)[idx] == (unsigned char)c)
			break ;
		idx++;
	}
	if (idx == n)
		return ((void *)0);
	return (dst + idx + 1);	
}
