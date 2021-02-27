/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:53:17 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/26 22:36:42 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(char *dest, char *src)
{
	int		i;
	int		size1;
	int		size2;

	i = 0;
	size1 = strlen(dest);
	size2 = strlen(src);
	if (size1 != size2)
		return (size1 - size2);
	else if (dest[i] && src[i])
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		i++;
	}
	return (0);
}
