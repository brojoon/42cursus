/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:04:48 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 07:56:17 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	size_t	check;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			break ;
		ptr++;
	}
	return (*ptr == '\0' ? NULL : ptr);
}
