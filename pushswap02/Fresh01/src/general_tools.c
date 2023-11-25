
#include "../pushswap.h"

void free_chrarr(char **arr)
{
	int i;
	
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

int chr_arr_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
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
	while (current != NULL)
	{		
		current = current->element_down;
		i++;	
	}
	return (i);
}

struct stack	*ft_lstlast(struct stack *lst)
{
	struct stack	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->element_down != NULL)
	{
		current = current->element_down;
	}
	return (current);
}
