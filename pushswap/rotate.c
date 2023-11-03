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
static void	rotate(element **stack)
{
	element	*tmp;
	if(ps_lstsize(stack) < 1)
		return ;
	printf("\nAFTER LSTSIZE\n");
	tmp = *stack;
	*stack = (*stack)->element_down;			//new top one
	ft_lstlast(*stack)->element_down = tmp;		//old top one gets attached to lastone
	tmp->element_down = NULL;
	ft_lstlast(*stack)->element_tail = *stack;	//stack stays on top
}

/* do_ra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	do_ra(element **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

/* do_rb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	do_rb(element **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

/* do_rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	do_rr(element **stack_a, element **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
