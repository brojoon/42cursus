/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:42:15 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 02:35:43 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	cur;

	if (!little)
		return ((char *)big);
	cur = 0;
	while ((cur < len) && big + cur)
	{
		idx = 0;
		while (big[cur + idx] == little[idx] && idx + cur < len)
		{
			idx++;
			if (!(little[idx]))
				return ((char *)(big + cur));
		}
		cur++;
	}
	return (0);
}
