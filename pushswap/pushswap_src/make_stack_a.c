#include "../include/pushswap.h"

void fill_list(element **elementnode_a, char **chr_arr, int argc)
{
	int i;
	struct stack  *new_element;
	info  *stack_data;

	stack_data = (struct data *)malloc(sizeof(struct data));
	if (!stack_data)
		return ;
	new_element = NULL;
	*elementnode_a = NULL;
	i = 0;
	while (i < argc)
	{
		new_element = ps_lstnew(ft_atoi(chr_arr[i]), stack_data);
		if (!new_element)
			return (ps_lstclear(elementnode_a));
		ps_lstadd_back(elementnode_a, new_element);
		i++;
	}
	(*elementnode_a)->stack_info->nbr_of_instructs = 1;
}

struct stack	*ps_lstnew(int content, info *stack_data)
{
	element	*rtn;

	rtn = (struct stack *)malloc(sizeof(struct stack));
	if (!rtn)
		return (NULL);
	(*rtn).value = content;
	(*rtn).stack_info = stack_data;
	(*rtn).cheapest = false;
	(*rtn).above_median = false;
	(*rtn).element_down = NULL;
	(*rtn).up = NULL;
	(*rtn).target = NULL;
	return (rtn);
}

void	ps_lstadd_back(element **lst, struct stack *new)
{
	struct stack	*tmp;
	
	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->element_down = NULL;
	}
	else
	{
		tmp = ps_lstlast(*lst);
		ps_lstlast(*lst)->element_down = new;
		new->up = tmp;
	}
}
void	ps_lstadd_front(element **lst, struct stack *new)
{
	struct stack	*last;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->element_down = NULL;
		(*lst)->cheapest = true;
	}
	else
	{
		new->element_down = *lst;
		*lst = new;
	}
}
