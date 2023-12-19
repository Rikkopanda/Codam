
#include "philosophers.h"

int create_philos(t_philosophers **philos, arguments *args)
{
	int i;
	fork_array *forks;

	*philos = malloc(sizeof(t_philosophers) * (*args).number_of_philosophers);
	forks = malloc(sizeof(forks) * (*args).number_of_philosophers);
	(*args).forks_ptr = forks;

	if(!philos)
		return (-1);
	i = 1;
	while(i <= (*args).number_of_philosophers)
	{
		(*philos)[i - 1].args = args;
		(*philos)[i - 1].philo_Nbr = i;
		//printf("creating...\n");
		pthread_create(&(*philos)[i - 1].th_id, NULL, routine, &(*philos)[i - 1]);
		i++;
	}
	//printf("done creating\n");
	return (1);
	//return (*philos);
}

void join_philos(t_philosophers *philos, int number_of_philosophers)
{
	int i;

	i = 0;
	while(i < number_of_philosophers)
	{
		pthread_join(philos[i].th_id, NULL);
		i++;
	}
}

int init_args(arguments *args, int argc, char **argv)
{
	int i;
	long long *argu_nbrs;

	if (argc < 5 || argc > 6)
		return (-1);
	argu_nbrs = malloc(sizeof(long long) * argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		argu_nbrs[i] = atoi(argv[i + 1]);
		i++;
	}
	(*args).number_of_philosophers = argu_nbrs[0];
	(*args).time_to_die = argu_nbrs[1];
	(*args).time_to_eat = argu_nbrs[2];
	(*args).time_to_sleep = argu_nbrs[3];
	if (argc > 5)
		(*args).number_of_times_each_philosopher_must_eat = argu_nbrs[4];
	else
		(*args).number_of_times_each_philosopher_must_eat = -1;
	free(argu_nbrs);
	return (0);
}
