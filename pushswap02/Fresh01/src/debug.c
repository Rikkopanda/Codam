
#include "../pushswap.h"

void print_lst(element **elements)
{
	element	*current;

	if (elements == NULL || *elements == NULL)
		return ;
	current = *elements;
	printf("\n");
	while (current->element_down != NULL)
	{
		printf("\n%d ", current->value);
		if(current->target != NULL)
			printf("target = %d\t cost = %d\t median = %d index = %d", current->target->value,  current->cost,  current->above_median,  current->index);
		current = current->element_down;
	}
	printf("\n%d ", current->value);
	if(current->target != NULL)
		printf("target = %d\t cost = %d\t median = %d index = %d", current->target->value,  current->cost,  current->above_median,  current->index);
	printf("\n\n");
}

void print_lst_debug(element **elements)
{
	element	*current;

	if (elements == NULL || *elements == NULL)
		return ;
	current = *elements;
	printf("\n");
	while (current->element_down != NULL)
	{
		printf("%d\t address = %p\tnext = %p\tup = %p\t instructs = %d\n", current->value, current, (current->element_down), (current->up), current->stack_info->nbr_of_instructs);
		current = current->element_down;
	}
	printf("%d\t address = %p\tnext = %p\tup = %p\n", current->value, current, (current->element_down), (current->up));

	printf("\n\n");
}
//printf("%d\t address = %p\tnext = %p\tup = %p\n", current->value, current, (current->element_down), (current->up));
//printf("target = %d\t cost = %d\t median = %d\n", current->target->value,  current->cost,  current->above_median);
