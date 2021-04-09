/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 07:51:12 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/03 22:28:25 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cur;

	if (!n)
		return (0);
	cur = -1;
	while (++cur < n)
	{
		if (((unsigned char *)s1)[cur] != ((unsigned char *)s2)[cur])
			break ;
	}
	if (cur == n)
		return (0);
	return (((unsigned char *)s1)[cur] - ((unsigned char *)s2)[cur]);
}
