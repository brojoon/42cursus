/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:06:47 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:06:48 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				*ft_util_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*suc;

	i = 0;
	suc = (unsigned char *)s;
	while (i < n)
	{
		suc[i] = 0;
		i++;
	}
	s = suc;
	return (suc);
}

size_t				ft_util_strlen(const char *str)
{
	size_t			cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt])
		cnt++;
	return (cnt);
}

void				*ft_util_memcpy(void *d, const void *s, size_t n)
{
	size_t			i;

	if (d == 0 && s == 0)
		return (d);
	i = 0;
	while (i < n)
	{
		((unsigned char *)d)[i] = ((unsigned char *)s)[i];
		++i;
	}
	return (d);
}

char				*ft_util_strjoin(char *st1, char *st2)
{
	char			*rst;
	size_t			ln1;
	size_t			ln2;

	if (!st1 && !st2)
		return (ft_util_strdup(""));
	if (st1 && !st2)
		return (ft_util_strdup(st1));
	if (!st1 && st2)
		return (ft_util_strdup(st2));
	ln1 = ft_util_strlen(st1);
	ln2 = ft_util_strlen(st2);
	if (!(rst = (char *)malloc(sizeof(char) * (ln1 + ln2 + 1))))
		return (0);
	ft_util_memcpy(rst, st1, ln1);
	ft_util_memcpy(rst + ln1, st2, ln2);
	rst[ln1 + ln2] = 0;
	return (rst);
}

char				*ft_util_strdup(char *str)
{
	char			*rst;
	int				idx;

	idx = ft_util_strlen(str);
	rst = (char *)malloc(sizeof(char) * (idx + 1));
	if (!rst)
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		rst[idx] = str[idx];
		++idx;
	}
	rst[idx] = '\0';
	return (rst);
}
