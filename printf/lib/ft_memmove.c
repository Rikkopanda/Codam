
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	void *ret_ptr;
	unsigned char placeholder[n];
	unsigned char* dst2;
	size_t i;
	
	dst2 = dest;
	ret_ptr = dst2;
	i = 0;
	while(i < n)
		placeholder[i++] = *(unsigned char*)src++;
	i = 0;
	while(i < n)
	{
		dst2[i] = placeholder[i];
		i++;
	}
	return (ret_ptr);
}

//int main()
//{
//	char src[] = "yeeahboii";
//	char dst[] = "oke";
//	char *ptr = ft_memmove(dst, src, ft_strlen(src) + 1);
//	int i = 0;
//	printf("%s\n", dst);
//}