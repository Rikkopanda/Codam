
#include "pushswap.h"

int gemalloced;
int gefreeed;

void free_chrarr(char **arr)
{
	int i;
	
	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
	gefreeed = gefreeed + i + 2;
	printf("\nfrees in strarr%d\n", gefreeed);
}

int chr_arr_size(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

int ps_lstsize(element **elements)
{
	struct stack	*current;
	int i;

	i = 0;
	if (elements == NULL)
		return (0);
	current = *elements;
	while (current->element_down != NULL)
	{		
		current = current->element_down;
		i++;	
	}
	return (i);
}
//printf("size %d", i);

void print_lst(element **elements)
{
	element	*current;

	if (elements == NULL)
		return ;
	current = *elements;
	while (current->element_down != NULL)
	{
		printf("%d \ttail = %p\t\tnext = %p\n", current->value, (current->element_tail), (current->element_down));
		current = current->element_down;
	}
	printf("%d \ttail = %p\t\tnext = %p\n", current->value, (current->element_tail), (current->element_down));
}
