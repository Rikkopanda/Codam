#include "../pushswap.h"

static bool dest_is_null(element **src, element **dest, element *tmp)
{
	if (*dest == NULL)
	{
		tmp = *src;
		*src = (*src)->element_down;
		*dest = tmp;
		(*dest)->element_down = NULL;
		(*dest)->up = NULL;
		(*src)->up = NULL;
		return (1);
	}
	return (0);
}

static bool src_is_single(element **src, element **dest)
{
	if ((*src)->element_down == NULL)
	{
		(*src)->element_down = *dest;
		*dest = *src;
		*src = NULL;
		return (1);
	}
	return (0);
}

static void	push(element **src, element **dest)
{
	element *tmp;

	if (*src == NULL)
		return ;
	if (src_is_single(src, dest))
		return ;
	tmp = (*src)->element_down;
	if (dest_is_null(src, dest, tmp))
		return ;
	(*src)->element_down = *dest;
	*dest = *src;
	(*dest)->up = NULL;
	(*dest)->element_down->up = *dest;
	*src = tmp;	
	(*src)->up = NULL;
}

/* do_pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	do_pa(element **stack_a, element **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (*stack_a)
		(*stack_a)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

/* do_pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	do_pb(element **stack_a, element **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (*stack_a)
		(*stack_a)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
