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

#include "../pushswap.h"

/* rotate:
*	The top element of the stack is sent to the bottom.
*/
static void	reverse_rotate(element **stack)
{
	element	*last;

	if (!*stack || !(*stack)->element_down)
		return ;
	last = ft_lstlast(*stack);
	last->up->element_down = NULL;
	last->element_down = *stack;
	last->up = NULL;
	*stack = last;
	last->element_down->up = last;
}
//last->up->element_down = NULL; 		//Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
//last->element_down = *stack; 			//Assign to its own `next` attribute as the top node of the stack
//last->up = NULL; 						//Detach itself from the node before it
//*stack = last;  						//Complete appending itself to the top of the stack, and now holds the pointer to the top node
//last->element_down->up = last;		//Update the current last node of the stack

/* do_rra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	do_rra(element **stack_a, bool print)
{
	reverse_rotate(stack_a);
	(*stack_a)->stack_info->nbr_of_instructs++;
	if(print)
		ft_putstr_fd("rra\n", 1);
}

/* do_rrb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	do_rrb(element **stack_b, bool print)
{
	reverse_rotate(stack_b);
	(*stack_b)->stack_info->nbr_of_instructs++;
	if(print)
		ft_putstr_fd("rrb\n", 1);
}

/* do_rrr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rrr" to the standard output.
*/
void	do_rrr(element **stack_a, element **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	(*stack_a)->stack_info->nbr_of_instructs++;
	if(print)
		ft_putstr_fd("rrr\n", 1);
}
