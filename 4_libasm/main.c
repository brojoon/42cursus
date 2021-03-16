#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#define	BUFFERSIZE 100000

char	ft_buf[BUFFERSIZE];
char	buf[BUFFERSIZE];

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
	int		fd;

	char	*dupstr;
	char	*ft_dupstr;

	printf("I will use Makefile to test\n");
	if ((fd = open("Makefile", O_RDONLY)) == 0)
	{
		printf("wrong file");
		return (0);
	}
	printf("read how many bytes was readed: %ld\n", read(fd, buf, 10000));
	close(fd);
	if ((fd = open("Makefile", O_RDONLY)) == 0)
	{
		printf("wrong file");
		return (0);
	}
	printf("ft_read() how many bytes was readed: %ld\n", read(fd, ft_buf, 10000));
	close(fd);
	printf("strcmp(makefile, ft_makefile) : %d strlen(ft_makefile) : %ld\n",
			strcmp(buf, ft_buf), strlen(buf));
	printf("ft_strcmp(makefile, ft_makefile) : %d ft_strlen(ft_makefile) : %d\n",
			ft_strcmp(buf, ft_buf), ft_strlen(ft_buf));
	dupstr = strdup(buf);
	ft_dupstr = strdup(ft_buf);
	printf("strcmp(dup_makefile, ft_dup_makefile) : %d\n", strcmp(dupstr, ft_dupstr));
	printf("ft_strcmp(dup_makefile, ft_dup_makefile) : %d\n", ft_strcmp(dupstr, ft_dupstr));
	free(dupstr);
	free(ft_dupstr);
	return (0);
}