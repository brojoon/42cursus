#include "libft.h"

int ft_isalnum(int c)
{
  return ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9');
}