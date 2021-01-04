/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 07:15:10 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/05 04:24:51 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		catch_new_line(char **line, char **memo)
{
	int		len;
	int		cur;
	int		i;

	len = 0;
	while ((*memo)[len] && (*memo)[len] != '\n')
		len++;
	if (!(*line = (char *)malloc(len + 1)))
		return (catch_error(memo));
	cur = -1;
	while (++cur < len)
		(*line)[cur] = (*memo)[cur];
	(*line)[cur] = '\0';
	if (*(memo)[cur] == '\n')
		return (catch_eof(line, memo));
	i = 0;
	while ((*memo)[len + 1 + i])
		memo[i++] = memo[len + 1 + i];
	return (READ);
}

int		catch_eof(char **line, char **memo)
{
	char	*tmp;

	if (!line)
	{
		tmp = (char *)malloc(1);
		*tmp = '\0';
		*line = tmp;
	}
	if (*memo)
		free(*memo);
	memo = NULL;
	return (EOF);
}

int		catch_error(char **memo)
{
	if (*memo)
		free(*memo);
	*memo = NULL;
	return (ERROR);
}

int		get_next_line(int fd, char **line)
{
	static char		*memo[FD_MAX + 1];
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	long long		byte;

	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE <= 0 \
	|| read(fd, buff, 0))
		return (ERROR);
	byte = 0;
	while (!(ft_strchar(memo[fd], '\n')) && \
	(byte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byte] = '\0';
		tmp = ft_strjoin(memo[fd], buff);
		if (memo[fd])
			free(memo[fd]);
		memo[fd] = tmp;
	}
	if (byte < 0)
		return (catch_error(&(memo[fd])));
	if (byte == 0 && memo[fd][0] == '\0')
		return (catch_eof(line, &(memo[fd])));
	return (catch_new_line(line, &(memo[fd])));
}
