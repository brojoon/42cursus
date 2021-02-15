/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:10:39 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/03 06:16:49 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t		src_len;
	size_t		dst_len;
	size_t		i;
	size_t		j;

	src_len = ft_strlen(src);
	if (destsize == 0)
		return (src_len);
	i = 0;
	while (dst[i] && i < destsize)
		i++;
	dst_len = i;
	j = 0;
	if (i < destsize)
	{
		while (i < (destsize - 1) && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (destsize - 1 < dst_len)
		return (destsize + src_len);
	return (src_len + dst_len);
}
