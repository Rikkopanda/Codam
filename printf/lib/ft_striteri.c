
#include "libft.h"


void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	if (!s || !f)
		return ;
	i = 0;
	while(s[i] != '\0')
	{
		f(i, &s[i]);
		write(1,&s[i], 1);
		i++;
	}
}//not working???

//void function(unsigned int a, char* str)
//{
//	str[a] = str[a] + 3;
//}
//int main()
//{
//	char str[] = "bbbbb";
//	ft_striteri(str, function);
//	//printf("%s", str);
//}
