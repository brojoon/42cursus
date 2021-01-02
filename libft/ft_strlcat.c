/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:10:38 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/03 00:51:28 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t cur;
	size_t dest_len;
	size_t src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (src_len + 1 < destsize)
	{
		while (*dest)
			dest++;
		cur = 0;
		while ((cur < destsize - src_len - 1) && src[cur])
		{
			*(dest) = src[cur];
			dest++;
			cur++;
		}
		*dest = '\0';
	}
	if (src_len > destsize)
		return (destsize + dest_len);
	return (src_len + dest_len);
}
