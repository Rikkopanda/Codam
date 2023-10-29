
#include "libft.h"

char *ft_strdup(const char *s)
{
	int len;
	char *new_str;
	char *str;

	str = (char *)s;
	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * len + 1);
	ft_strcpy(new_str, str);
	
	return (new_str);
}
