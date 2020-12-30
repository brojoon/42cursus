/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:42:15 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/31 05:51:35 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	cur;
	char	*result;

	cur = 0;
	result = (char *)big;
	while ((cur < len) && *result)
	{
		idx = 0;
		while (idx < ft_strlen(little))
		{
			if (result[cur] != little[cur] || (idx + cur) >= len)
				break ;
			idx++;
		}
		if (idx == ft_strlen(little))
			return (result);
		result++;
	}
	return (0);
}
