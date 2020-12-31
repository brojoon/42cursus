/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:15:38 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 08:18:14 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = -1;
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (ptr)
	{
		while (++i < ft_strlen(s1))
			ptr[i] = s1[i];
		ptr[i] = '\0';
	}
	return (ptr);
}
