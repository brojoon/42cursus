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

#endif