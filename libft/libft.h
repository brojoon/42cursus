#ifndef LIBFT
#define LIBFT

#include <unistd.h>

unsigned ft_strlcpy(char *dest, const char *src, unsigned size);
unsigned ft_strlen(const char *s);
unsigned ft_strlcat(char *dest, const char *src, unsigned size);
void *ft_memset(void *b, int c, size_t len)

    int ft_strncmp(const char *s1, const char *s2, unsigned int size);
int ft_atoi(const char *str);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_isalpha(int c);

#endif