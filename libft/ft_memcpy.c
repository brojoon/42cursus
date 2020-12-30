/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:02:58 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/31 01:00:03 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return (dst);
	while (len--)
		(*((unsigned char *)dst++)) = (*((unsigned char *)src++));
	return (dst);
}
