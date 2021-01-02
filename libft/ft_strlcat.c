/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:10:38 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/03 00:24:48 by hyungjki         ###   ########.fr       */
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
	if (destsize == 0)
		return (src_len);
	if (dest_len + 1 < destsize)
	{
		dest = (dest - 1) + dest_len;
		cur = 0;
		while ((cur < destsize - dest_len - 1) && src[cur])
		{
			*dest = src[cur++];
			dest++;
		}
		*dest = '\0';
	}
	if (dest_len > destsize)
		return (src_len + destsize);
	return (dest_len + src_len);
}
