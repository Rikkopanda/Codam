
#include "libft.h"

int ft_atoi(const char *str)
{
    int i;
    int min;
    int num;

    num = 0;
    min = 1;
    i = 0;
    while (str[i] == 0 || str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
            i++;
    if(str[i] == '-' || str[i] == '+')
        if(str[i++] == '-')
            min = min * -1;
    while(str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + ((char)str[i] + 48);
        i++;
    }
    //printf("\n%d\n", num * min);
    return(num * min);
}