/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:00:55 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 08:00:57 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	ft_free_split(char **paths)
{
	int	i;

	i = -1;
	if (paths)
	{
		while (paths[++i])
			free(paths[i]);
		free(paths);
	}
}

char			*find_value(char *key, char **envp)
{
	int	i;

	i = -1;
	while (envp && envp[++i])
	{
		if (!ft_strncmp(envp[i], key, ft_strlen(key)))
			return (envp[i] + ft_strlen(key) + 1);
	}
	return (0);
}

char			*get_path(char *cmd, char **envp)
{
	int			i;
	char		*temp;
	char		*new_path;
	char		**paths;
	struct stat	s;

	temp = find_value("PATH", envp);
	paths = ft_split(temp, ':');
	i = -1;
	
	while (paths && paths[++i])
	{
		temp = ft_strjoin("/", cmd);
		new_path = ft_strjoin(paths[i], temp);
		free(temp);
		if (stat(new_path, &s) == 0)
		{
			ft_free_split(paths);
			return (new_path);
		}
		free(new_path);
	}
	ft_free_split(paths);
	return (0);
}

int		err_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (1);
}

char	*inst_join(char *str1, char*str2)
{
	char *tmp;
	char *ret;

	tmp = ft_strjoin(str1, " ");
	ret = ft_strjoin(tmp, str2);
	free(tmp);
	return (ret);	
}