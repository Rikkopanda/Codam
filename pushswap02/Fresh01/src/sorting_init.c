#include "../pushswap.h"

void init_stack_a(element **node_a, element **node_b)
{
	index_assign(node_a);
	index_assign(node_b);
	assign_targets_a(*node_a, *node_b);
	calc_cost_a(node_a, node_b);
	assign_cheapest(*node_a);
}

void init_stack_b(element **node_a, element **node_b)
{
	index_assign(node_a);
	index_assign(node_b);
	assign_targets_b(*node_a, *node_b);
	calc_cost_a(node_a, node_b);
	assign_cheapest(*node_a);
}

void index_assign(element **node)
{
	element *current;
	int i;
	int median;

	if (*node == NULL)
		return ;
	i = 0;
	current = *node;
	median = ps_lstsize(node) / 2;
	while (current != NULL)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->element_down;
		i++;
	}
}

void calc_cost_a(element **node_a, element **node_b)
{
	element *current_a;

	current_a = *node_a;
	while (current_a)
	{
		if (current_a->index <= ps_lstsize(node_a) / 2)
			current_a->cost = current_a->index;
		else
			current_a->cost = ps_lstsize(node_a) - current_a->index;
		if (current_a->target->index <= ps_lstsize(node_b) / 2)
			current_a->cost += current_a->target->index;
		else
			current_a->cost += ps_lstsize(node_b) - current_a->target->index;
		current_a = current_a->element_down;
	}
}

void assign_cheapest(element *node_a)
{
	element *cheapest;

	cheapest = node_a;
	while (node_a)
	{
		if (node_a->cost < cheapest->cost)
			cheapest = node_a;
		node_a = node_a->element_down;
	}
	cheapest->cheapest = true;
}



