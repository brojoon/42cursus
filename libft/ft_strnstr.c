/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:42:15 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 16:44:39 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	cur;
	char	*result;

	if (!big || !little || !len)
		return (0);
	cur = 0;
	result = (char *)big;
	while ((cur < len) && *(result + cur))
	{
		idx = 0;
		while (idx < ft_strlen(little))
		{
			if (result[cur + idx] != little[idx] || (idx + cur) >= len)
				break ;
			idx++;
		}
		if (idx == ft_strlen(little))
			return (result);
		cur++;
	}
	return (0);
}
