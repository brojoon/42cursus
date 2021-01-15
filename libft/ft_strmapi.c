/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:18:29 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/30 06:42:35 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	idx;

	result = (char *)malloc(ft_strlen(s) + 1);
	if (result)
	{
		idx = 0;
		while (idx < ft_strlen(s))
		{
			result[idx] = (*f)(idx, s[idx]);
			idx++;
		}
		result[idx] = '\0';
	}
	return (result);
}
