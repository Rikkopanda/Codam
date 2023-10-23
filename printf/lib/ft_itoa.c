
#include "libft.h"

int begin_check(int *n, int *i, char *str1)
{
	if(*n == -2147483647)
	{
		ft_strcpy(str1, "-2147483647");
		return (1);
	}
	if(*n < 0)
	{
		str1[*i] = '-';
		*n = *n * -1;
		//printf("char %c, i = %d\n", str1[*i], *i);
		*i = *i + 1;
	}
	return (0);
}

char *ft_itoa(int n)
{
	char *str1;
	int i;
	int tal;

	str1 = (char *)malloc(sizeof(char) * 20);
	if(str1 == NULL)
		return(NULL);
	i = 0;
	tal = 1000000000;
	if(begin_check(&n, &i, str1) == 1)
		return (str1);
	while(n > 9)
	{
		if(n / tal == 0)
			tal = tal / 10;
		else
		{
			str1[i++] = (n / tal) + 48;
			n = n % tal;
		}
	}
	if(n <= 9)
	{
		str1[i++] = n + 48;
	}
	str1[i] = '\0';
	return (str1);
}
//int main()
//{
//	char *test = ft_itoa(-2147483646);
//	printf("%s", test);
//	free(test);
//}