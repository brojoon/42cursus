#include "libft.h"

unsigned ft_strlcat(char *dest, const char *src, unsigned size)
{
   unsigned int i;
   unsigned int j;

   i = 0;
   j = 0;
   while (dest[i] != '\0')
    i++;
   while (i + j + 1 < size && src[j])
   {
     dest[i + j] = src[j];
     j++;
   }
   dest[i + j] = '\0';
   while (src[j] != '\0')
        j++;
    if (i > size)
      return (size + j)
    return(i + j);
}