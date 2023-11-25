
#include "pushswap.h"

static void	push(element **src, element **dest)
{
	element *tmp;

	if (*src == NULL)
		return ;
	if (*dest == NULL)
		(*src)->element_tail = *src;
	else
		(*src)->element_tail = NULL;
	
	tmp = (*src)->element_down;						//one after head src

	(*src)->element_down = *dest;					//next one of head dest

	*dest = *src;									//assign head dest

	ps_lstlast(*dest)->element_tail = *dest;

	ps_lstlast(*dest)->element_down = NULL;			//

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
	ft_putstr_fd("pa\n", 1);
}