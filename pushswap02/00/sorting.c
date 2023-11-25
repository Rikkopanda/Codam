
#include "pushswap.h"
#include <limits.h>

void scan_stack(element **stack, info *data)
{
	struct stack	*current;
	int i;

	i = 0;
	if (*stack == NULL)
		return ;
	current = *stack;
	i = 1;
	while (current->element_down != NULL)
	{	
		data->stack_arr[i] = current->value;
		current = current->element_down;
		i++;
	}
	data->stack_arr[i] = current->value;
	data->live_size = i;
	//data->last_val = current->value;
	i++;
	while(i < data->ini_size_a)
	{
		data->stack_arr[i] = '\0';
		i++;
	}
}


void scan_print(element **node_a, element **node_b, info *a_data, info *b_data)
{
	scan_stack(node_b, b_data);
	scan_stack(node_a, a_data);
	print_data_stack(a_data);
	print_data_stack(b_data);
	printf("\n");
}

void bamischijf(element **node_a, element **node_b, info *a_data, info *b_data)
{
	int i;

	i = 0;
	while(i < a_data->ini_size_a)
	{
		scan_print(node_a, node_b, a_data, b_data);
		//do_rra(node_a);
		//do_rb(node_a);
		i++;
	}
}
int first0second1last2(element **stack_a)
{
	int first;
	int second;
	int last;

	first = (*stack_a)->value;
	last = ft_lstlast(*stack_a)->value;
	if((*stack_a)->element_down != NULL)
		second = (*stack_a)->element_down->value;
	//printf("bbbbbb\n");
	if(first <= last && first <= second)
		return (0);
	if(last < first && last < second)
		return (1);
	if(second < first || second <= last)
		return (2);
	return (3);
}

void burrito(element **node_a, element **node_b, info *a_data, info *b_data)
{

	//if(a_data->stack_arr[a_data->live_size - 1] < b_data->stack_arr[0] || b_data->live_size == 0)
	//{
	//	do_ra(node_b);
	//	do_pb(node_a, node_b);
	//	if(b_data->live_size > 0)
	//		do_rb(node_b);
	//}//vooraf push
	//else
	scan_stack(node_a, a_data);
	scan_stack(node_b, b_data);
	if(first0second1last2(node_a) == 0)
		do_pb(node_a, node_b);
	else if(first0second1last2(node_a) == 1)
	{
		do_sa(node_a);
		do_pb(node_a, node_b);
	}
	else if(first0second1last2(node_a) == 2)
	{
		do_ra(node_a);
		do_pb(node_a, node_b);
		//printf("cccccc\n");
	}
	//scan_print(node_a, node_b, a_data, b_data);
	//scan_print(node_a, node_b, a_data, b_data);
	//a_data->nbr_of_instructs++;
	////scan_stack(node_b, b_data);
	//if((*node_b)->value >= a_data->biggest)
	//	a_data->biggest = (*node_b)->value;
	//else if((*node_b)->value <= a_data->smallest)// maak global data voor
	//{
	//	a_data->smallest = (*node_b)->value;
	//	do_rb(node_b);
	//	a_data->nbr_of_instructs++;
	//}
	//else if(a_data->stack_arr[1] > b_data->stack_arr[0])
	scan_stack(node_a, a_data);
	scan_stack(node_b, b_data);
}

void init_data(element **stack, info *data, int size)
{
	data->biggest = INT_MIN;
	data->smallest = INT_MAX;
	data->nbr_of_instructs = 0;
	data->live_size = 0;
	data->stack_arr = calloc(size, sizeof(int));
	data->ini_size_a = size;
}

void print_data_stack(info *data)
{
	int i;

	i = 1;
	while (i <= data->ini_size_a)
	{	
		printf("%d ", data->stack_arr[i]);
		i++;
	}
	printf("%d ", data->stack_arr[i]);
	printf("\n");
}

int elements_sorted(element *node_a, element *node_b, info *a_data, info *b_data)
{
	//scan_stack(&node_b, b_data);
	//scan_stack(&node_a, a_data);
	scan_print(&node_a, &node_b, a_data, b_data);
	scan_print(&node_a, &node_b, a_data, b_data);
	int i;
	int j;

	j = 0;
	i = 0;
	printf("size a %d\n", a_data->live_size);
	printf("size b %d\n", b_data->live_size);
	if(b_data->live_size > 0)
		return (0);
	while(i < a_data->ini_size_a - 1)
	{
		if(a_data->stack_arr[i] > a_data->stack_arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int sort_list(element **elements_a, int size)
{
	element *node_b;
	element *tmp;
	info a_data;
	info b_data;

	node_b = NULL;
	init_data(elements_a, &a_data, size);
	init_data(&node_b, &b_data, size);
	
	int i;
	i = 0;
	//scan_print(elements_a, &node_b, &a_data, &b_data);
	//scan_print(elements_a, &node_b, &a_data, &b_data);
	while(!elements_sorted(*elements_a, node_b, &a_data, &b_data) && i < 5
			)
	{
		//printf("aaaaaa\n");
		burrito(elements_a, &node_b, &a_data, &b_data);
		i++;
	}
	printf("\n");
	//print_lst(&node_b);
	//ft_lstclear(&node_b);
	//return (a_data.nbr_of_instructs);
	return (0);
}

//printf("smallest\t%d\n" , data.smallest);
//printf("biggest\t%d\n" , data.biggest);