/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:10:38 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 23:12:23 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t src_len;
	size_t m;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (dest[i] && i < size)
		i++;
	m = i;
	while (i + 1 < size && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (size - 1 < m)
		return (size + src_len);
	return (src_len + m);
}
