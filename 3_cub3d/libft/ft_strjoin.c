/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:52:56 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/26 22:23:24 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int k)
{
	char	*result;
	int		cur;
	int		i;

	i = -1;
	cur = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
	{
		while (s1[++i])
			result[cur++] = s1[i];
		i = -1;
		while (s2[++i])
			result[cur++] = s2[i];
		result[cur] = '\0';
	}
	if ((k == 1 || k == 3) && s1)
		free((char *)s1);
	if ((k == 2 || k == 3) && s2)
		free((char *)s2);
	return (result);
}
