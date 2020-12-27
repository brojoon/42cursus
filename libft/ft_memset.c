#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
  unsigned char *tmp;

  tmp = (unsigned char *)b;
  for (size_t i = 0; i < len; i++)
    *(tmp++) = (unsigned char)c;
  return (b);
}