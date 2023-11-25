
#include "pushswap.h"

static void	push(element **src, element **dest)
{
	element *tmp;

	if (*src == NULL)
		return ;
	if ((*src)->element_down == NULL)
	{
		(*src)->element_down = *dest;
		*dest = *src;
		*src = NULL;
		return ;
	}
	tmp = (*src)->element_down;					//one after head src
	if(*dest == NULL)
	{
		*dest = *src;
		(*dest)->cheapest = true;
		(*src)->element_down = NULL;
		*src = tmp;
		(*src)->cheapest = true;
		return ;
	}
	(*src)->element_down = *dest;
	(*src)->element_down->cheapest = false;
	*dest = *src;
	(*dest)->cheapest = true;						//assign head dest										
	tmp->cheapest = true;
	*src = tmp;										//head of src changed
}

/* do_pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	do_pa(element **stack_a, element **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

/* do_pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	do_pb(element **stack_a, element **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}