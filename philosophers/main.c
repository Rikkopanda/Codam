
#include "philosophers.h"

int cont = 0;

int main(int argc, char **argv)
{
	arguments args;
	philosophers *philos;

	if(init_args(&args, argc, argv) == -1)
		return (-1);
	if(create_philos(&philos, &args) == -1)
		return (-1);
	join_philos(philos, args.number_of_philosophers);

	free(philos);
	printf("cont: %d\n", cont);
}
