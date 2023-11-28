#ifndef PRINTBOOL
#  define PRINTBOOL 1
#endif
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef enum { false, true } bool;

typedef struct stack
{
	struct stack *up;
	struct stack *element_down;
	struct stack *target;
	bool cheapest;
	bool above_median;
	int index;
	int value;
	int cost;
	bool minimum;
	bool maximum;
	struct data *stack_info;
	//info *stack_b_info;
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


//make stack_a
void			fill_list(element **elementnode_a, char **argv, int argc);
struct stack	*ps_lstnew(int content, info *stack_data);
void			ps_lstadd_back(element **lst, struct stack *new);
struct stack	*ps_lstlast(struct stack *lst);

//clear list
void	ps_lstclear(element **element_a);
void	ps_lstdelone(element *element_a);

//general_tools
int		ps_lstsize(element **elements);
int		chr_arr_size(char **arr);
void	free_chrarr(char **arr);
void	print_data_stack(info *data);
void	ps_lstadd_front(element **lst, struct stack *new);

//sorting_tools
void	sort_three_ascend(element **node_a);
void	sort_three_descend(element **node_a);
element	*find_biggest(element *node);
element	*find_smallest(element *node);

//--------------------------------algoritihm--------------------------
int		sort_list(element **elements_a, int size);
void	turk_algorith(element **node_a, element **node_b);
//init_stacks
void init_stack_a(element **node_a, element **node_b);
void init_stack_b(element **node_a, element **node_b);
void index_assign(element **node);
void calc_cost_a(element **node_a, element **node_b);
void assign_cheapest(element *node_a);
//set targets
void assign_targets_a(element *node_a, element *node_b);
void assign_targets_b(element *node_a, element *node_b);
//push_nodes
void	push_node(element **src_node, element **dest_node, bool what_stack);
void	prepare_stack(element **stack, element *push_node,
		void (*rotate)(element **node, bool print),
		void (*rev_rotate)(element **target_stack, bool print));
void	rotate_both(element **src_node, element **dest_node, element *cheapest);
element	*find_cheapest(element *node);

//--------------------------------commands--------------------------
//push
void	do_pa(element **stack_a, element **stack_b, bool print);
void	do_pb(element **stack_a, element **stack_b, bool print);

// rotate
void	do_rr(element **stack_a, element **stack_b, bool print);
void	do_ra(element **stack_a, bool print);
void	do_rb(element **stack_b, bool print);

// reverse rotate
void	do_rra(element **stack_a, bool print);
void	do_rrb(element **stack_b, bool print);
void	do_rrr(element **stack_a, element **stack_b, bool print);

//switch
void	do_sa(element **stack_a, bool print);
void	do_sb(element **stack_b, bool print);
void	do_ss(element **stack_a, element **stack_b, bool print);

// debug

void print_lst(element **elements);
void print_lst_debug(element **elements);

#endif
