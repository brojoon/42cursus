/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:04:48 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/06 02:51:47 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchar(char const *s, int c)
{
	int		i;
	char	*result;

	i = -1;
	result = (char *)s;
	while (result[++i])
	{
		if (result[i] == c)
			return (result + i);
	}
	return (0);
}
