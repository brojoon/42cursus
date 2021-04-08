/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 03:27:09 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/08 04:59:09 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(void)
{
	char	*result;

	result = (char *)malloc(1);
	*result = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		cur;

	cur = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
	{
		while (*s1)
		{
			result[cur++] = *s1;
			s1++;
		}
		while (*s2)
		{
			result[cur++] = *s2;
			s2++;
		}
		result[cur] = '\0';
	}
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			break ;
		ptr++;
	}
	if (*ptr == '\0' && c != '\0')
		return (NULL);
	return (ptr);
}
