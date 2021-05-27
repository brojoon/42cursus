/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:52:19 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/30 21:05:29 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*nullptr_return(void)
{
	char	*result;

	result = (char *)malloc(1);
	*result = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		idx;
	size_t	size;

	if (!s)
		return (NULL);
	idx = ft_strlen(s);
	if (idx <= start)
		return (nullptr_return());
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	result = (char *)malloc((len + 1));
	if (result)
	{
		idx = -1;
		while (++idx < (int)len)
			result[idx] = s[(int)start + idx];
		result[len] = '\0';
		return (result);
	}
	return (result);
}
