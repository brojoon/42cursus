/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:53:49 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/30 00:48:01 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	cur;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && is_set(s1[start], set))
		start++;
	while (end >= 0 && is_set(s1[end], set))
		end--;
	result = (char *)malloc(((start > end) ? 0 : end - start + 1) + 1);
	if (result)
	{
		cur = 0;
		if (start <= end)
		{
			while (cur <= end - start)
				result[cur++] = s1[start + cur];
		}
		result[cur] = '\0';
	}
	return (result);
}
