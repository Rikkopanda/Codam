
#include "libft.h"

void ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
		
	dest[i] = '\0';
}
