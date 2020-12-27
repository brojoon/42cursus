#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
  unsigned char *tmp;
  unsigned const char *s;

  if (!dst && !src)
    return (dst);
  if (dst <= src)
  {
    tmp = (unsigned char)dst;
    s = (unsigned const char)src;
    while (len--)
      *tmp++ = *s++;
  }
  else
  {
    tmp = dst;
    tmp += len;
    s = src;
    s += len;
    while (len--)
      *--tmp = *--s;
  }
  return (dst);
}