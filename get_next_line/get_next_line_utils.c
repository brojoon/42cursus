/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 07:06:50 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/05 04:23:16 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char		*ft_strchar(char const *s, int c)
{
	int		i;
	char	*result;

	i = -1;
	result = (char *)s;
	while (result[++i])
	{
		if (result[i] == c)
			return (result + i);
	}
	return (0);
}
