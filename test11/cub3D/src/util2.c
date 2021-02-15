/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:06:16 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:06:33 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t				ft_util_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t			sdx;
	size_t			idx;

	sdx = 0;
	idx = 0;
	while (src[sdx])
		++sdx;
	if (siz == 0)
		return (sdx);
	while (src[idx] && idx < siz - 1)
	{
		dst[idx] = src[idx];
		++idx;
	}
	dst[idx] = '\0';
	return (sdx);
}

size_t				ft_util_strlcat(char *dst, const char *src,
	size_t siz)
{
	size_t			idx;
	size_t			ddx;
	size_t			sdx;

	ddx = ft_util_strlen(dst);
	sdx = ft_util_strlen(src);
	idx = 0;
	while (src[idx] && ddx + 1 + idx < siz)
	{
		dst[ddx + idx] = src[idx];
		++idx;
	}
	dst[ddx + idx] = '\0';
	if (siz < ddx)
		return (siz + sdx);
	return (ddx + sdx);
}

int					ft_util_is_empty(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int					ft_util_is_number(char c)
{
	return (c >= 48 && c <= 57);
}

int					ft_util_is_printable(char c)
{
	return ((c >= 32 && c <= 126) ? c : 0);
}
