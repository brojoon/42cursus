/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:54:16 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 18:07:15 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strslen(const char *s, char c)
{
	size_t		result;
	size_t		flag;

	result = 0;
	flag = 0;
	while (*s)
	{
		if (!(flag) && *s != c)
			flag = 1;
		if (flag && *s == c)
		{
			result++;
			flag = 0;
		}
		s++;
	}
	if (flag)
		result++;
	return (result);
}

static size_t	free_strs(char **result, size_t cur)
{
	size_t		idx;

	idx = 0;
	while (idx < cur)
		free(result[idx++]);
	return (1);
}

static size_t	init_split(char **result, char const *s, char c)
{
	size_t		cur;
	size_t		len;
	char		*sep;

	cur = 0;
	len = 0;
	while (*s)
	{
		if (len == 0 && *s != c)
			sep = (char *)s;
		if (*s != c)
		{
			len++;
			s++;
		}
		if (len && *s == c || s == NULL)
		{
			result[cur] = ft_substr(sep, 0, len);
			if (!(result[cur++]))
				return (free_strs(result, cur));
			len = 0;
		}
		s++;
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char **) * (strslen(s, c) + 1));
	if (result && init_split(result, s, c))
	{
		free(result);
		result = NULL;
	}
	return (result);
}
