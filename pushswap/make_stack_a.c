#include "pushswap.h"

extern int gemalloced;
extern int gefreeed;
void fill_list(element **elementnode_a, char **chr_arr, int argc)
{
	int i;
	struct stack  *new_element;

	new_element = NULL;
	i = 0;
	while(i < argc)
	{
		//printf("%d ", ft_atoi(chr_arr[i]));
		new_element = ft_lstnew(ft_atoi(chr_arr[i]));
		if(!new_element)
			return(ft_lstclear(elementnode_a));
		ft_lstadd_back(elementnode_a, new_element);
		i++;
	}
}

struct stack	*ft_lstnew(int content)
{
	element	*rtn;

	rtn = (struct stack *)malloc(sizeof(struct stack));
	gemalloced++;
	if (!rtn)
		return (NULL);
	(*rtn).value = content;
	(*rtn).element_tail = NULL;
	(*rtn).minimum = false;
	(*rtn).element_up = NULL;
	(*rtn).element_down = NULL;
	return (rtn);
}

void	ft_lstadd_back(element **lst, struct stack *new)
{
	struct stack	*last;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->element_tail = *lst;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->element_down = new;
		last->element_tail = NULL;
		new->element_tail = *lst;
	}
}

struct stack	*ft_lstlast(struct stack *lst)
{
	struct stack	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->element_down != NULL)
		current = current->element_down;
	return (current);
}

void	ft_lstclear(element **element_a)
{
	element	*tmp;
	gefreeed = 0;
	if (!element_a || !*element_a)
		return ;
	if (element_a)
	{
		while ((*element_a)->element_tail == NULL)
		{
			tmp = (*element_a)->element_down;
			ft_lstdelone(*element_a);
			*element_a = tmp;
		}
		ft_lstdelone(*element_a);
	}
	printf("\nfrees in ft_lstclear%d\n", gefreeed);
	element_a = 0;
}

void	ft_lstdelone(element *element_a)
{
	if (!element_a)
		return ;
	free(element_a);
	gefreeed = gefreeed + 1;
	//printf("\nfrees in strarr%d\n", gefreeed);
	element_a = 0;
}
