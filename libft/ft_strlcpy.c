#include "libft.h"

unsigned ft_strlcpy(char *dest, const char* src, unsigned size)
{
  unsigned i;

  i = 0;
  while (i + 1 < size && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  while (src[i] != '\0')
    i++;
  return (i);
}