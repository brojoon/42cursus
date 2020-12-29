/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:41:52 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/28 10:01:03 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t cur;

	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		cur = len;
		while (cur-- > 0)
			*((unsigned char *)dst + cur) = *((unsigned char *)src + cur);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
