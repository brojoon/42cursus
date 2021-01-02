/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:26:01 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 17:25:08 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;
	size_t m;

	i = 0;
	j = 0;
	k = 0;
	while (src[k])
		k++;
	if (size == 0)
		return (k);
	while (dest[i] && i < size)
		i++;
	m = i;
	if (i < size)
	{
		while (i < (size - 1) && src[j])
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	if (size - 1 < m)
		return (size + k);
	return (k + m);
}
