
#include "../include/pushswap.h"
#include <limits.h>

void turk_algorith(element **node_a, element **node_b)
{
	do_pb(node_a, node_b, PRINTBOOL);
	do_pb(node_a, node_b, PRINTBOOL);
	// printf("print B1:\n");
	// print_lst_debug(node_b);
	// print_lst_debug(node_a);

	while (ps_lstsize(node_a) > 3)
	{
		init_stack_a(node_a, node_b);
		push_node(node_a, node_b, 1);
		//outer function 2\n");
		// print_lst_debug(node_a);
		// printf("print B2:\n");
		// print_lst_debug(node_b);
	}
	if (ps_lstsize(node_a) == 3)
		sort_three_ascend(node_a);
		// printf("print B3:\n");
	// print_lst_debug(node_b);
	// print_lst_debug(node_a);
	while (*node_b)
	{
		init_stack_b(node_b, node_a);
		// printf("print B4:\n");
		// print_lst_debug(node_b);
		// print_lst_debug(node_a);
		push_node(node_b, node_a, 0);
		// printf("print B5:\n");
		// print_lst_debug(node_b);
		// print_lst_debug(node_a);
		// printf("in outer function 2\n");
	}
	while (find_smallest(*node_a) != *node_a)
	{
		if (find_smallest(*node_a)->above_median)
			do_ra(node_a, PRINTBOOL);
		else
			do_rra(node_a, PRINTBOOL);
	}
	// print_lst_debug(node_a);
	// print_lst_debug(node_b);
}
//printf("\na = %d" , ps_lstsize(node_a));
//print_lst_debug(node_a);
//printf("\nb = %d" , ps_lstsize(node_b));
//print_lst_debug(node_b);
//print_lst_debug(node_b);
//print_lst_debug(node_a);

int stack_sorted(element *node_a, element *node_b)
{
	int i;
	element *node_current;

	i = 0;
	node_current = node_a;
	// printf("lstsize %d\n", ps_lstsize(&node_a));
	while (i < ps_lstsize(&node_a) - 1)
	{
		// printf("lstsize %d\n", ps_lstsize(&node_a));
		if (node_current->value > node_current->element_down->value)
			return (0);
		i++;
		node_current = node_current->element_down;
	}
	
	return (1);
}

int sort_list(element **elements_a, int size)
{
	element *node_b;

	node_b = NULL;
	if (!stack_sorted(*elements_a, node_b))
	{
		if (ps_lstsize(elements_a) == 2)
			do_sa(elements_a, PRINTBOOL);
		else if (ps_lstsize(elements_a) == 3)
			sort_three_ascend(elements_a);
		else
			turk_algorith(elements_a, &node_b);
	}
	return (0);
}
//printf("smallest\t%d\n" , data.smallest);
//printf("biggest\t%d\n" , data.biggest);
//init_data(elements_a, &a_data, size);
//init_data(&node_b, &b_data, size);