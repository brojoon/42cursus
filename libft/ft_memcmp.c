/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 07:51:02 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/03 01:02:26 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ptt1;
	unsigned char *ptr2;

	ptt1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n--)
		if (*ptt1++ != *ptr2++)
			return ((ptt1 - 1) - (ptr2 - 1));
	return (0);
}
