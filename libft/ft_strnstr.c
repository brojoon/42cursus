/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:42:15 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/30 04:06:12 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	cur;
	char	*find;

	cur = 0;
	while (len-- && big[cur])
	{
		idx = 0;
		while (idx < ft_strlen(little))
		{
			if (big[idx + cur] != little[idx] || idx + cur >= len)
				break ;
			idx++;
		}
		if (idx == ft_strlen(little))
			return (big);
		cur++;
	}
	return (0);
}
