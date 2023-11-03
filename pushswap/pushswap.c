
#include "pushswap.h"

int gemalloced;
int gefreeed;

int main(int argc, char **argv)
{
	element *elementnode_a;

	elementnode_a = NULL;
	char **list_elements;
	int nbr_instructs;
	gemalloced = 0;
	gefreeed = 0;
	if(argc == 1)
		return (1);
	if(ft_strchr(argv[1], ' ') != NULL && argc == 2)
	{
		list_elements = ft_split(argv[1], ' ');
		fill_list(&elementnode_a, list_elements, chr_arr_size(list_elements));
		free_chrarr(list_elements);
	}
	//else
		//fill_list(&elementnode_a, &argv[1], argc - 1);
	if(elementnode_a == NULL)
		return (1);
	print_lst(&elementnode_a);
	nbr_instructs = sort_list(&elementnode_a, ps_lstsize(&elementnode_a));
	printf("instructs: %d wat is pointer a: %p", nbr_instructs, elementnode_a);
	printf("\n\nmallocs: %d", gemalloced);
	//ft_lstclear(&elementnode_a);
}