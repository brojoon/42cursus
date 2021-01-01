/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:42:15 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 06:18:29 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t len;

	if (*little == '\0')
		return (char *)big;
	len = ft_strlen(little);
	while (*big && size-- >= len)
	{
		if (*big == *little && ft_strncmp(big, little, len) == 0)
			return (char*)big;
		big++;
	}
	return (0);
}
