#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#define	BUFFERSIZE 100000

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

ssize_t ft_write(int fd, void const *buf, size_t bytes);
ssize_t ft_read(int fd, void *buf, size_t bytes);
int		ft_strlen(char const *s1);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strdup(char const *s1);
char	*ft_strcpy(char *dst, char const *src);

void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);

int main(void)
{
	
	return (0);
}