
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;

    substr = (char*)malloc(sizeof(char) * len);
    printf("%d char malloc\n", len);
    if(substr == NULL)
        return(NULL);
    i = 0;
    while(i < len - 1)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}

// int main()
// {
//     char *str = "hallo dit is ene test";
//     char *str2;
//     str2 = ft_substr(str, 6, 9);
//     printf("%s", str2);
//     free(str2);
// }