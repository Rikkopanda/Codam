
#include "pushswap.h"
#include <limits.h>



void burrito(element **elements_a, element **elementnode_b, info *data)
{
	do_pb(elements_a, elementnode_b);
	data->nbr_of_instructs++;
	if((*elementnode_b)->value >= data->biggest)
		data->biggest = (*elementnode_b)->value;
	if((*elementnode_b)->value <= data->smallest)
	{
		data->smallest = (*elementnode_b)->value;
		do_rb(elementnode_b);
		data->nbr_of_instructs++;
	}
	
}

int sort_list(element **elements_a, int size)
{
	element *elementnode_b;
	element *tmp;
	info data;
	elementnode_b = NULL;
	data.biggest = INT_MIN;
	data.smallest = INT_MAX;
	data.nbr_of_instructs = 0;
	while((*elements_a)->element_down != NULL)
		burrito(elements_a, &elementnode_b, &data);
	burrito(elements_a, &elementnode_b, &data);
	print_lst(&elementnode_b);
	ps_lstclear(&elementnode_b);
	return (data.nbr_of_instructs);
}

//printf("smallest\t%d\n" , data.smallest);
//printf("biggest\t%d\n" , data.biggest);