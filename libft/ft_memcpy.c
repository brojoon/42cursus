#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t len)
{
  unsigned char *s1;

  if (!dst && !src)
    return (dst);
  s1 = (unsigned char *)dst;
  while (len--)
  {
    *s1 = *((unsigned const char *)src);
    s1++;
    src++;
  }
  return (dst);
}