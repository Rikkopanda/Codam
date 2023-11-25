/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:18:17 by mcombeau          #+#    #+#             */
/*   Updated: 2022/09/28 11:13:19 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* rotate:
*	The top element of the stack is sent to the bottom.
*/
static void	reverse_rotate(element **stack)
{
	element	*tmp;
	if(ps_lstsize(stack) < 1)
		return ;
	tmp = *stack;
	ft_lstlast(*stack)->element_down = tmp;//old top one gets attached to lastone
	*stack = ft_lstlast(*stack);		//new top one
	(*stack)->element_down = tmp;
	//ft_lstlast(*stack)->element_tail =  		
	//tmp->element_down = NULL;
	//ft_lstlast(*stack)->element_tail = *stack;	//stack stays on top
}

/* do_ra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	do_rra(element **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

/* do_rb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	do_rrb(element **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

/* do_rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	do_rrr(element **stack_a, element **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
