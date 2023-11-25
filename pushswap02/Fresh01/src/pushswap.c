
#include "../pushswap.h"

int main(int argc, char **argv)
{
	element *node_a;

	node_a = NULL;
	if (argc == 1)
		return (1);
	if (ft_strchr(argv[1], ' ') != NULL && argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = &argv[1];
	fill_list(&node_a, argv, chr_arr_size(argv));
	if (node_a == NULL)
		return (1);
	sort_list(&node_a, ps_lstsize(&node_a));
	printf("%d\n", node_a->stack_info->nbr_of_instructs);
	ft_lstclear(&node_a);
}
