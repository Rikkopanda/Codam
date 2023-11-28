
#include "../include/pushswap.h"

int main(int argc, char **argv)
{
	element *node_a;
	int list_size;

	node_a = NULL;
	if (argc == 1)
		return (1);
	if (ft_strchr(argv[1], ' ') != NULL && argc == 2)
	{
		argv = ft_split(argv[1], ' ');
	}
	else
		argv = &argv[1];
	// printf("%s\n", argv[1]);
	// argv[argc - 1] = NULL;
	fill_list(&node_a, argv, chr_arr_size(argv));
	// printf("%s\n", argv[1]);
	if (node_a == NULL)
		return (1);
	// print_lst(&node_a);
	// print_lst_debug(&node_a);

	sort_list(&node_a, ps_lstsize(&node_a));
	// printf(" hello ");
	// print_lst(&node_a);
	// printf("%s\n", argv[1]);
	// printf("%d\n", node_a->stack_info->nbr_of_instructs);
	ps_lstclear(&node_a);
}

