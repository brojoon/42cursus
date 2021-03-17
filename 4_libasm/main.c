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
	printf("ft_read() how many bytes was readed: %ld\n", ft_read(fd, ft_buf, 10000));
	close(fd);
	printf("strcmp(buf, ft_buf) : %d strlen(buf) : %ld\n",
			strcmp(buf, ft_buf), strlen(buf));
	printf("ft_strcmp(buf, ft_buf) : %d ft_strlen(ft_buf) : %d\n",
			ft_strcmp(buf, ft_buf), ft_strlen(ft_buf));
	dupstr = strdup(buf);
	ft_dupstr = ft_strdup(ft_buf);
	printf("strcmp(dupstr, ft_dupstr) : %d\n", strcmp(dupstr, ft_dupstr));
	printf("ft_strcmp(dupstr, ft_dupstr) : %d\n", ft_strcmp(dupstr, ft_dupstr));
	if ((fd = open("test_write.txt", O_RDWR)) == 0)
	{
		printf("opne failed");
		return (0);
	}
	write(fd, "hello write", 11);
	close(fd);
	if ((fd = open("test_ft_write.txt", O_RDWR)) == 0)
	{
		printf("opne failed");
		return (0);
	}
	ft_write(fd, "hello ft_write", 14);
	close(fd);
	char *str1 = "hellodd1";
	char *str2 = "hello0o";
	printf("strcmp(str1, str2) : %d\n", strcmp(str1, str2));
	printf("ft_strcmp(str1, str2) : %d\n", ft_strcmp(str1, str2));
	return (0);
}