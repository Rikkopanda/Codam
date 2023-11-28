
#include "../include/pushswap.h"

element *find_biggest(element *node)
{
	element *biggest;

	if (NULL == node)
		return (NULL);
	biggest = node;
	while (node)
	{
		if (node->value > biggest->value)
			biggest = node;
		node = node->element_down;
	}
	return (biggest);
}

element *find_smallest(element *node)
{
	element *biggest;

	if (NULL == node)
		return (NULL);
	biggest = node;
	while (node)
	{
		if (node->value < biggest->value)
			biggest = node;
		node = node->element_down;
	}
	return (biggest);
}

void sort_three_descend(element **node_a)
{
	element	*smallest_node;

	smallest_node = find_smallest(*node_a);
	if (*node_a == smallest_node)
		do_ra(node_a, PRINTBOOL);
	else if ((*node_a)->element_down == smallest_node)
		do_rra(node_a, PRINTBOOL);
	if ((*node_a)->value < (*node_a)->element_down->value)
		do_sa(node_a, PRINTBOOL);
}

void sort_three_ascend(element **node_a)
{
	element	*highest_node;

	highest_node = find_biggest(*node_a);
	if (*node_a == highest_node)
		do_ra(node_a, PRINTBOOL);
	else if ((*node_a)->element_down == highest_node)
		do_rra(node_a, PRINTBOOL);
	if ((*node_a)->value > (*node_a)->element_down->value)
		do_sa(node_a, PRINTBOOL);
}