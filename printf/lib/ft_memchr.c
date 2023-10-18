
#include "libft.h"

void *ft_memchr(const void *str, int c, size_t n)
{

	if(c > 256)
		c = c - 256;
	while(n-- > 0)
	{
		if(*(unsigned char*)str == c)
			return (void*)(str);
		str++;
	}
	return (NULL);
}