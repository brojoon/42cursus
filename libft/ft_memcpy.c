/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:02:58 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/31 08:41:07 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*result;
	
	if (!dst && !src)
		return (dst);
	result = (unsigned char *)dst;
	while (len--)
		(*(result++)) = (*((unsigned char *)src++));
	return (dst);
}
