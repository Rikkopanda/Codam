
#include "pushswap.h"

static void	swap(element **stack)
{
	element *tmp;

	tmp = *stack;
	(*stack)->element_down = *stack;
	*stack = tmp;
}

/* do_sa:
*	Swaps the top element of stack a with second.
*	Prints "sa" to the standard output.
*/

void do_sa(element **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void do_sb(element **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void do_ss(element **stack_a, element **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}