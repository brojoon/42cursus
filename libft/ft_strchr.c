/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:04:48 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/31 06:26:07 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	size_t	check;

	check = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			break ;
		if (*ptr == '\0')
		{
			check = 1;
			break ;
		}
		ptr++;
	}
	return (check ? NULL : ptr);
}
