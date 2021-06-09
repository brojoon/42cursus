/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:52:56 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/06 03:05:19 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		cur;
	int		i;

	cur = 0;
	i = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
	{
		while (s1[i])
			result[cur++] = s1[i++];
		i = 0;
		while (s2[i])
			result[cur++] = s2[i++];
		result[cur] = '\0';
	}
	return (result);
}
