
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    if(!nmemb || !size)
    {
        ptr = malloc(1);
        if(!ptr)
            return (NULL);
        ft_bzero(ptr, 1);
        return (ptr);
    }
    if((nmemb * size)/size != nmemb)
        return (NULL);
    ptr = malloc(nmemb * size);
    if(!ptr)
        return (NULL);
    ft_bzero(ptr, nmemb * size);
    return(ptr);
}
// int main()
// {
//     int len;

//     len = 4;
//     char *test = (char*)calloc(len, sizeof(char));
//     write(1, &test[1],1);
//     free(test);
// }