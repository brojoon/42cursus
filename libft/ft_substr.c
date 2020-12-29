/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:52:09 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/30 02:43:38 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	idx;
	size_t	size;

	if (!s)
		return (NULL);
	idx = 0;
	size = ft_strlen(s);
	if (size <= start)
	{
		result = (char *)malloc(1);
		*result = '\0';
		return (result);
	}
	result = (char *)malloc((len + 1));
	if (result)
	{
		while (idx < len)
			result[idx++] = s[start + idx];
		return (result[len] = '\0');
	}
	return (result);
}
