
#include "../../include/pushswap.h"


static void	swap(element **stack)
{
	element *tmp;

	tmp = *stack;
	*stack = (*stack)->element_down;
	tmp->element_down = (*stack)->element_down;
	(*stack)->element_down = tmp;
	(*stack)->element_down->up = *stack;
	(*stack)->element_down->element_down->up = (*stack)->element_down;
	(*stack)->up = NULL;
}
//very confusing to read
//use printdebug function for clarifying

/* do_sa:
*	Swaps the top element of stack a with second.
*	Prints "sa" to the standard output.
*/

void do_sa(element **stack_a, bool print)
{
	swap(stack_a);
	if(print)
		ft_putstr_fd("sa\n", 1);
}

void do_sb(element **stack_b, bool print)
{
	swap(stack_b);
	if(print)
		ft_putstr_fd("sb\n", 1);
}

void do_ss(element **stack_a, element **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if(print)
		ft_putstr_fd("ss\n", 1);
}
