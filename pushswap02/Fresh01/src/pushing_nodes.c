#include "../pushswap.h"

void push_node(element **src_node, element **dest_node, bool what_stack)
{
	element *cheapest;

	cheapest = find_cheapest(*src_node);
	rotate_both(src_node, dest_node, cheapest);
	index_assign(dest_node);
	prepare_stack(src_node, cheapest, do_ra, do_rra);
	index_assign(dest_node);
	prepare_stack(dest_node, cheapest->target, do_rb, do_rrb);
	index_assign(dest_node);
	if (what_stack)
		do_pb(src_node, dest_node, PRINTBOOL);
	else
		do_pa(src_node, dest_node, PRINTBOOL);
}

/* prepare_stack:
*  rotate it untill it is on the top top position
*/ 
void prepare_stack(element **stack, element *push_node,
		void (*rotate)(element **node, bool print),
		void (*rev_rotate)(element **target_stack, bool print))
{
	if (push_node->above_median == true)
		while (push_node != *stack)
			rotate(stack, PRINTBOOL);
	else
		while (push_node != *stack)
			rev_rotate(stack, PRINTBOOL);
}

/* rotate_both:
*  rotates both when they are both above or below the median line
*  until one of them is on the top position
*/ 
void rotate_both(element **src_node, element **dest_node, element *cheapest)
{
	bool target_med = cheapest->target->above_median;

	if (cheapest->above_median == true && target_med == true)
		while (cheapest != *src_node && cheapest->target != *dest_node)
			do_rr(src_node, dest_node, PRINTBOOL);
	else if (cheapest->above_median == false && target_med == false)
		while (cheapest != *src_node && cheapest->target != *dest_node)
			do_rrr(src_node, dest_node, PRINTBOOL);
}

element *find_cheapest(element *node)
{
	while (node)
	{
		if (node->cheapest == true)
			return (node);
		node = node->element_down;
	}
	return (node);
}