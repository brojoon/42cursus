/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:00:50 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 08:00:51 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	exec_proc(char **cmd, char **envp)
{
	char		*path;

	path = 0;
	path = get_path(cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd(cmd[0], 2);
		ft_putendl_fd(": command not found", 2);
	}
	else
		execve(path, cmd, envp);
	exit(1);
}

void	exec_cmd(char *cmd, int fds[2], int pipes[2], char **envp)
{
	close(pipes[0]);
	dup2(pipes[1], 1);
	dup2(fds[0], 0);
	close(pipes[1]);
	exec_proc(ft_split(cmd, ' '), envp);
}

void	exec_cmd2(char *cmd, int fds[2], int pipes[2], char **envp)
{
	close(pipes[1]);
	dup2(pipes[0], 0);
	dup2(fds[1], 1);
	close(pipes[0]);
	exec_proc(ft_split(cmd, ' '), envp);
}

void parsing_and_exec_init(char **argv, pid_t pid, \
int fds[], int pipes[], char **envp)
{
	char *cmd;
	char *cmd2;

	if (argv[3][0] == '-' || !ft_strcmp(argv[2], "grep"))
	{
		cmd = inst_join(argv[2], argv[3]);
		if (argv[5][0] == '-' || !ft_strcmp(argv[4], "grep"))
			cmd2 = inst_join(argv[4], argv[5]);
		else
			cmd2 = argv[4];
	}
	else
	{
		cmd = argv[2];
		if (argv[4][0] == '-' || !ft_strcmp(argv[3], "grep"))
			cmd2 = inst_join(argv[3], argv[4]);
		else
			cmd2 = argv[3];
	}
	pid = fork();
	if (pid == 0)
		exec_cmd(cmd, fds, pipes, envp);
	else
		exec_cmd2(cmd2, fds, pipes, envp);
}

int		main(int argc, char *argv[], char **envp)
{
	int		fds[2];
	int		pipes[2];
	pid_t	pid;

	pid = 0;
	if (argc < 5 || argc > 7)
		return (err_msg("argument error!!"));
	if ((fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (err_msg("open file2: failed!!"));
	if ((fds[0] = open(argv[1], O_RDONLY)) == -1)
		return (err_msg("open file1: failed!!"));
	if (pipe(pipes) == -1)
		return (err_msg("pipe: failed!!"));
	parsing_and_exec_init(argv, pid, fds, pipes, envp);
	close(fds[0]);
	close(fds[1]);
	return (0);
}