/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:02:59 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 17:15:15 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*result;
	unsigned char	*tmp;

	if (!dst && !src)
		return (dst);
	result = (unsigned char *)dst;
	tmp = (unsigned char*)src;
	while (len--)
		*result++ = *tmp++;
	return (dst);
}
