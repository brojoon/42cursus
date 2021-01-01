/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:54:16 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 01:03:02 by hyungjki         ###   ########.fr       */
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

	idx = -1;
	while (++idx < cur)
	{
		free(result[idx]);
		result[idx] = NULL;
	}
	return (1);
}

static size_t	init_split(char **result, const char *s, char c, size_t len)
{
	size_t	cur;
	size_t	count;
	size_t	i;

	cur = 0;
	len = 0;
	while (s[i] && i < len)
	{
		count = 0;
		if (s[i] != c)
		{
			while (s[i + count] != c && s[i + count])
				count++;
			result[cur] = ft_substr(s, i, count);
			if (!result[cur])
				return (free_strs(result, cur));
			cur++;
		}
		i += 1 + count;
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	len;

	if (!s)
		return (NULL);
	len = strslen(s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (0);
	if (init_split(result, s, c, len))
	{
		free(result);
		result = NULL;
		return (result);
	}
	result[len] = 0;
	return (result);
}
