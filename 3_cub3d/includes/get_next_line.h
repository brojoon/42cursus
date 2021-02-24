/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 03:27:07 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/24 14:23:58 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define FD_MAX 98765
# define READ 1
# define END 0
# define ERROR -1

int		get_next_line(int fd, char **line);
char	*ft_gnl_strdup(void);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strpush(char *s, int push);

#endif
