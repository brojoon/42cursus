/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:00:52 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 08:01:05 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>

char			*get_path(char *cmdline, char **envs);
char			*find_value(char *key, char **envs);
int				err_msg(char *msg);
char			*inst_join(char *str1, char*str2);
void			ft_free_split(char **paths);

#endif