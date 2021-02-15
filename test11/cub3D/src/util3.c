/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:06:52 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:09:28 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_util_str_size(char *str, int idx)
{
	int				rst;

	rst = 0;
	while (ft_util_is_printable(str[idx + rst]) &&
		str[idx + rst] != '\t' && str[idx + rst] != '\n' &&
		str[idx + rst] != '\r' && str[idx + rst] != '\v' &&
		str[idx + rst] != ' ')
		++rst;
	return (rst);
}

int					ft_util_str_to_int(char *str, int idx)
{
	int				rst;

	rst = 0;
	while (ft_util_is_number(str[idx]))
		rst = (rst * 10) + (str[idx++] - '0');
	return (rst);
}

char				*ft_util_substr(char const *str, unsigned int stt,
	size_t len)
{
	size_t	idx;
	char	*rst;

	if (!str)
		return (void *)0;
	if ((size_t)stt > ft_util_strlen(str))
		return (ft_util_strdup(""));
	idx = 0;
	rst = (char *)malloc(sizeof(char) * (len + 1));
	while (idx < len)
	{
		rst[idx] = *(str + stt + idx);
		++idx;
	}
	rst[idx] = '\0';
	return (rst);
}

int					ft_util_strncmp(const char *st1, const char *st2,
	size_t num)
{
	size_t			i;

	i = 0;
	while (i < num && (st1[i] || st2[i]))
	{
		if (st1[i] != st2[i])
			return ((unsigned char)st1[i] - (unsigned char)st2[i]);
		++i;
	}
	return (0);
}

int					ft_util_lstsize(t_lst *lst)
{
	int				cnt;

	cnt = 0;
	while (lst)
	{
		lst = lst->nxt;
		++cnt;
	}
	return (cnt);
}
