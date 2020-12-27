#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, unsigned int size)
{
  unsigned int n;

  n = 0;
  while (n < size && s1[n] && s2[n])
  {
    if (s1[n] != s2[n])
      break;
    n++;
  }
  if (n == size)
    return (0);
  return s1[n] - s2[n];
}