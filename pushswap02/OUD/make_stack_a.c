#include "pushswap.h"

extern int gemalloced;
extern int gefreeed;
void fill_list(element **elementnode_a, char **chr_arr, int argc)
{
	int i;
	struct stack  *new_element;
	new_element = NULL;
	*elementnode_a = NULL;
	i = 0;
	while(i < argc)
	{
		//printf("%d \n", ft_atoi(chr_arr[i]));
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
	(*rtn).cheapest = false;
	(*rtn).element_down = NULL;
	//printf("%d address = %p\t\tnext = %p\n", rtn->value, rtn, NULL);
	return (rtn);
}

void	ft_lstadd_back(element **lst, struct stack *new)
{
	struct stack	*last;
	
	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->element_down = NULL;
	}
	else
	{
		ft_lstlast(*lst)->element_down = new;
	}
	//printf("%d\n", ft_lstlast(*lst)->value);
}
void	ft_lstadd_front(element **lst, struct stack *new)
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
	//printf("%d\n", ft_lstlast(*lst)->value);
}

struct stack	*ft_lstlast(struct stack *lst)
{
	struct stack	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->element_down != NULL)
	{
		current = current->element_down;
		//printf("%d\n", current->value);
	}
		
	return (current);
}
struct stack	*ps_lst_ret_nonext(struct stack *lst)
{
	struct stack	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->element_down->cheapest != true)
	{
		if(current->element_down == NULL)
		{
			//current->element_down = lst;
			break ;
		}
		current = current->element_down;
		//printf("AAA\t%d\t address = %p\tcheapest? %d\tnext = %p\n", current->value, current, (*current).cheapest, (current->element_down));
		//printf("%d\n", current->value);
	}
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
		while ((*element_a)->element_down->cheapest == false)
		{
			tmp = (*element_a)->element_down;
			//printf("%d address = %p FREED \t\tnext = %p\n ", (*element_a)->value, *element_a, ((*element_a)->element_down));
			ft_lstdelone(*element_a);
			*element_a = tmp;
		}
		//printf("%d address = %p FREED \t\tnext = %p\n ", (*element_a)->value, *element_a, ((*element_a)->element_down));
		ft_lstdelone(*element_a);
		
	}
	//printf("\nfrees in ft_lstclear%d\n", gefreeed);
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
