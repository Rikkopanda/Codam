#include "../pushswap.h"

void	ft_lstclear(element **element_a)
{
	element	*tmp;

	if (!element_a || !*element_a)
		return ;
	free((*element_a)->stack_info);
	(*element_a)->stack_info = 0;
	if (element_a)
	{
		while ((*element_a)->element_down != NULL)
		{
			tmp = (*element_a)->element_down;
			ft_lstdelone(*element_a);
			*element_a = tmp;
		}
		ft_lstdelone(*element_a);
	}
	element_a = 0;
}
//printf("%d address = %p FREED \t\tnext = %p\n ", (*element_a)->value, *element_a, ((*element_a)->element_down));

void	ft_lstdelone(element *element_a)
{
	if (!element_a)
		return ;
	free(element_a);
	element_a = 0;
}
