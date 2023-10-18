
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	size_t j;
	const int size_int = size;

	i = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while(dst[i])
		i++;
	j = 0;
	while(i < size_int - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	j = ft_strlen((char *)src);
	return (ft_strlen(dst) + ft_strlen((char *)src));
}
// appends size - strlen(dst) - 1

//int main()
//{
//	char str1[] = "test";
//	char str2[] = "123";
//	int size = strlcat(str1, str2, 9);
//	printf("%s\n", str1);
//	printf("size %d", size);
//}


//	"B\0"  = dest