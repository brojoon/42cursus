/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:52:55 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/06 02:34:52 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*result;

	if (!s1 || !s2)
		return (0);
	result = (char *)malloc(sizeof(ft_strlen(s1)) + sizeof(ft_strlen(s2)) + 1);
	if (result)
	{
		i = -1;
		while (s1[++i])
			result[i] = s1[i];
		j = i;
		i = -1;
		while (s2[++i])
			result[j + i] = s2[i];
		result[j + i] = '\0';
	}
	return (result);
}
