
#include "libft.h"



char *ft_strtrim(char const *s1, char const *set)
{
	char *s2;
	int begin_i;
	int len;
	int i;
	char *rtn;

	begin_i = 0;
	i = 0;
	len = 0;
	s2 = (char *)s1;
	while(check_char_set(s2[begin_i], (char *)set))
		begin_i++;
	while(s2[begin_i + i] != '\0')
	{
		if(!check_char_set(s2[begin_i + i], (char *)set))
			len = i + 1;
		i++;
	}
	rtn = ft_substr(s1, begin_i, len + 1);
	return (rtn);
}
// set = ab
//			len  = 6
//				 01234 5
//				 6   10
// str =   aaaabbTEaST \0bbba // eerste niet set en laatste niet set.
// str = TEaST
//int main()
//{
//	char *test = ft_strtrim("aaaabbbbba" , "ab");
//	printf("%s", test);
//}