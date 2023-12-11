
#include "pipex.h"


void free_arr(void **ptr)
{
	int i;

	i = 0;
	while(ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
			char argv2stack[3][10];
}
