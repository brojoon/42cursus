/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:48:31 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/28 10:03:04 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*dst;
	unsigned char	*tmp;
	size_t			len;

	len = 0;
	dst = malloc(count * size);
	if (dst)
	{
		tmp = (unsigned char *)dst;
		while (len++ < size * count)
			*(tmp++) = 0;
	}
	return (dst);
}
