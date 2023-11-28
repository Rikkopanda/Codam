#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef enum { false, true } bool;

typedef struct stack
{
	struct stack *up;
	struct stack *element_down;
	bool cheapest;
	bool above_median;
	int index;
	int value;
}	element;

typedef struct data
{
	int *stack_arr;
	int last_val;
	int live_size;
	int ini_size_a;
	int smallest;
	int biggest;
	int nbr_of_instructs;
}	info;

//tools
void print_lst(element **elements);
int ps_lstsize(element **elements);
int chr_arr_size(char **arr);
void free_chrarr(char **arr);
void print_data_stack(info *data);
struct stack	*ps_lst_ret_nonext(struct stack *lst);
void	ft_lstadd_front(element **lst, struct stack *new);

//make stack_a

void fill_list(element **elementnode_a, char **argv, int argc);
struct stack	*ft_lstnew(int content);
void	ft_lstadd_back(element **lst, struct stack *new);
struct stack	*ft_lstlast(struct stack *lst);
void	ft_lstclear(element **element_a);
void	ft_lstdelone(element *element_a);
int ps_lstsize(element **elements);
static void	swap(element **stack);
void do_sa(element **stack_a);
void do_sb(element **stack_b);
void do_ss(element **stack_a, element **stack_b);
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

// reverse rotate

static void	reverse_rotate(element **stack);
void	do_rra(element **stack_a);
void	do_rrb(element **stack_b);
void	do_rrr(element **stack_a, element **stack_b);

#endif
