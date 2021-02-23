/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 03:27:09 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/22 06:15:13 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strdup(void)
{
	char	*result;

	result = (char *)malloc(1);
	*result = '\0';
	return (result);
}

size_t	ft_gnl_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		cur;
	int		i;

	cur = 0;
	i = -1;
	result = (char *)malloc(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1);
	if (result)
	{
		while (s1[++i])
			result[cur++] = s1[i];
		i = -1;
		while (s2[++i])
			result[cur++] = s2[i];
		result[cur] = '\0';
	}
	return (result);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			break ;
		ptr++;
	}
	return ((*ptr == '\0' && c != '\0') ? NULL : ptr);
}
