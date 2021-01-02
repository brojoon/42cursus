/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:10:38 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/03 01:02:20 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		l;

	k = 0;
	while (src[k])
		k++;
	if (destsize == 0)
		return (k);
	i = 0;
	while (dst[i] && i < destsize)
		i++;
	l = i;
	j = 0;
	if (i < destsize)
	{
		while (i < (destsize - 1) && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (destsize - 1 < l)
		return (destsize + k);
	return (k + l);
}
