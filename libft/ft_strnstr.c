/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:42:15 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 05:47:24 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t idx;
	size_t cur;

	if (little[0] == 0)
		return ((char *)big);
	cur = 0;
	while (big[cur] && cur < len)
	{
		idx = 0;
		while (big[cur + idx] == little[cur] && idx + cur < len)
		{
			cur++;
			if (little[cur] == 0)
				return ((char *)big + idx);
		}
		idx++;
	}
	return (0);
}
