#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef enum { false, true } bool;



typedef struct stack
{
	struct stack *element_tail;
	struct stack *element_up;
	struct stack *element_down;
	bool minimum;
	int value;
}	element;

typedef struct data
{
	int smallest;
	int biggest;
	int nbr_of_instructs;
}	info;

//tools
void print_lst(element **elements);
int chr_arr_size(char **arr);
void free_chrarr(char **arr);

//make stack_a

void fill_list(element **elementnode_a, char **argv, int argc);
struct stack	*ps_lstnew(int content);
void	ps_lstadd_back(element **lst, struct stack *new);
struct stack	*ps_lstlast(struct stack *lst);
void	ps_lstclear(element **element_a);
void	ps_lstdelone(element *element_a);
int ps_lstsize(element **elements);

//sorting

int sort_list(element **elements_a, int size);
static void	push(element **src, element **dest);

//push
void	do_pa(element **stack_a, element **stack_b);
void	do_pb(element **stack_a, element **stack_b);

// rotate
static void	rotate(element **stack);
void	do_rr(element **stack_a, element **stack_b);
void	do_ra(element **stack_a);
void	do_rb(element **stack_b);


#endif
