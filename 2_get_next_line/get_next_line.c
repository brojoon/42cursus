/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 06:40:28 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/08 06:40:29 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	catch_copy(char **line, char **memo)
{
	int		len;
	int		cur;

	len = 0;
	while ((*memo)[len] && (*memo)[len] != '\n')
		len++;
	*line = (char *)malloc(len + 1);
	if (!(*line))
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

void	catch_read(int fd, char **memo, ssize_t *len, char **buff)
{
	char	*tmp;

	while (*memo && (!(ft_strchr(*memo, '\n'))))
	{
		*len = read(fd, *buff, BUFFER_SIZE);
		if (*len <= 0)
			break ;
		(*buff)[(*len)] = '\0';
		tmp = ft_strjoin(*memo, *buff);
		if (*memo)
			free(*memo);
		*memo = tmp;
	}
}

int	get_next_line(int fd, char **line)
{
	ssize_t		len;
	char		*buff;
	static char	*memo[FD_MAX];

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || fd >= FD_MAX || !line || BUFFER_SIZE <= 0 || \
		read(fd, buff, 0) || !(buff))
	{
		free(buff);
		return (ERROR);
	}
	if (!memo[fd])
		memo[fd] = ft_strdup();
	catch_read(fd, &(memo[fd]), &len, &buff);
	free(buff);
	buff = NULL;
	if (len < 0 || memo[fd] == NULL)
		return (catch_error(&(memo[fd])));
	if (len == 0 && memo[fd][0] == '\0')
		return (catch_end(line, &(memo[fd])));
	return (catch_copy(line, &(memo[fd])));
}
