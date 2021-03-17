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
	
	t_list	list1;
	t_list	list2;
	t_list	list3;
	list1.data = "list1";
	list1.next = &list2;
	list2.data = "list2";
	list2.next = &list3;
	list3.data = "list3";
	list3.next = NULL;

	printf("list size: 3 / %d\n", ft_list_size(&list1));
	printf("list size: 3 / %d\n", ft_list_size(&list1));
	printf("list size: 3 / %d\n", ft_list_size(&list1));
	printf("list size: 2 / %d\n", ft_list_size(&list2));
	printf("list size: 1 / %d\n", ft_list_size(&list3));
	printf("list size: 0 / %d\n", ft_list_size(NULL));
	
	t_list list_new;
	list_new.next = NULL;
	t_list *push_front = &list_new;
	
	ft_list_push_front(&push_front, "hello list1");
	printf("pushed data: %s, pushed next %p\n", (char *)(push_front->data), push_front->next);
	printf("list size: / %d\n", ft_list_size(push_front));
	ft_list_push_front(&push_front, "hello list2");
	printf("pushed data: %s, pushed next %p\n", (char *)(push_front->data), push_front->next);
	printf("list size: / %d\n", ft_list_size(push_front));
	ft_list_push_front(&push_front, "hello list3");
	printf("pushed data: %s, pushed next %p\n", (char *)(push_front->data), push_front->next);
	printf("list size: / %d\n", ft_list_size(push_front));

	return (0);
}