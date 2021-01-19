/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 06:40:13 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/08 06:40:16 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	catch_error(char **memo)
{
	if (*memo)
		free(*memo);
	*memo = NULL;
	return (ERROR);
}

int	catch_end(char **line, char **memo)
{
	if (!(**memo))
		*line = ft_strdup();
	if (*memo)
		free(*memo);
	*memo = NULL;
	return (END);
}

int	catch_read(char **line, char **memo)
{
	int		len;
	int		cur;

	len = 0;
	while ((*memo)[len] && (*memo)[len] != '\n')
		len++;
	if (!(*line = (char *)malloc(len + 1)))
		return (catch_error(memo));
	cur = -1;
	while (++cur < len)
		(*line)[cur] = (*memo)[cur];
	(*line)[cur] = '\0';
	if ((*memo)[len] == '\0')
		return (catch_end(line, memo));
	cur = 0;
	while ((*memo)[len + 1 + cur])
	{
		(*memo)[cur] = (*memo)[len + 1 + cur];
		cur++;
	}
	(*memo)[cur] = '\0';
	return (READ);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		len;
	char		*buff;
	static char	*memo[FD_MAX];
	char		*tmp;

	if (fd < 0 || fd >= FD_MAX || !line || BUFFER_SIZE <= 0 || \
		!(buff = (char *)malloc(BUFFER_SIZE + 1)) || read(fd, buff, 0))
		return (ERROR);
	if (!memo[fd] && !(len = 0))
		memo[fd] = ft_strdup();
	while (memo[fd] && (!(ft_strchr(memo[fd], '\n'))) && \
			((len = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[len] = '\0';
		tmp = ft_strjoin(memo[fd], buff);
		if (memo[fd])
			free(memo[fd]);
		memo[fd] = tmp;
	}
	free(buff);
	if (((!(buff = NULL)) && len < 0) || memo[fd] == NULL)
		return (catch_error(&(memo[fd])));
	if (len == 0 && memo[fd][0] == '\0')
		return (catch_end(line, &(memo[fd])));
	return (catch_read(line, &(memo[fd])));
}
