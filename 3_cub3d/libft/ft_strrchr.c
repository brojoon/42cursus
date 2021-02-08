/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:50:44 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/06 02:38:47 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *end;

	if (c == '\0')
		return (ft_strchr(s, c));
	end = (char *)s;
	while (*end)
		end++;
	while (end != s && *end != (char)c)
		end--;
	if (*end == (char)c)
		return (end);
	return (0);
}
