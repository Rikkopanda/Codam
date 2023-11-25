#include "../pushswap.h"

void assign_targets_a(element *node_a, element *node_b)
{
	element *target_node;
	element *current_b;
	int closest_smaller;
	
	while (node_a)
	{
		closest_smaller = INT_MIN;
		current_b = node_b;
		while (current_b)
		{
			if (node_a->value > current_b->value && closest_smaller < current_b->value)
			{
				closest_smaller = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->element_down;
		}
		if (closest_smaller == INT_MIN)
			node_a->target = find_biggest(node_b);
		else
			node_a->target = target_node;
		node_a = node_a->element_down;
	}
}

void assign_targets_b(element *node_a, element *node_b)
{
	element *target_node;
	element *current_b;
	int closest_bigger;
	
	while (node_a)
	{
		closest_bigger = INT_MAX;
		current_b = node_b;
		while (current_b)
		{
			if (node_a->value < current_b->value && closest_bigger > current_b->value)
			{
				closest_bigger = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->element_down;
		}
		if (closest_bigger == INT_MAX)
			node_a->target = find_smallest(node_b);
		else
			node_a->target = target_node;
		node_a = node_a->element_down;
	}
}