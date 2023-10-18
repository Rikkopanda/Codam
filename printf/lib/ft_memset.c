
#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	size_t i;
	void *retptr = s;
	i = 0;
	while (i < n)
	{
		*(char*)s = c;
		s++;
		i++;
	}
	return (retptr);
}
//make use of restrict still