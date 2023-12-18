
#include "philosophers.h"

int cont = 0;
pthread_mutex_t lock;

void  *routine(void *voidptr)
{
	pointers *ptrs = (pointers *)voidptr;

	(*ptrs).philo->cnt_to_die = (*ptrs).args->time_to_die;
	while (0 < (*ptrs).philo->cnt_to_die)
	{
		pthread_mutex_lock(&lock);
		cont++;
		//(*ptrs).philo->cnt_to_die--;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

void *create_philos(philosophers **philos, arguments *args)
{
	int i;
	pointers *data_ptrs;

	*philos = malloc(sizeof(philosophers) * (*args).number_of_philosophers);
	if(!philos)
		return (NULL);
	data_ptrs = malloc(sizeof(pointers) * (*args).number_of_philosophers);
	if(!data_ptrs)
		return (NULL);
	i = 0;
	while(i < (*args).number_of_philosophers)
	{
		data_ptrs->args = args;
		data_ptrs->philo = &(*philos)[i];
		pthread_create(&(*philos)[i].th_id, NULL, &routine, data_ptrs);
		i++;
	}
	return (data_ptrs);
}

void join_philos(philosophers **philos, int number_of_philosophers)
{
	int i;

	i = 0;
	while(i < number_of_philosophers)
	{
		pthread_join((*philos)[i].th_id, NULL);
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

int main(int argc, char **argv)
{
	arguments args;
	philosophers *philos;
	pointers *ptrs;

	if(init_args(&args, argc, argv) == -1)
		return (-1);
	ptrs = create_philos(&philos, &args);
	if(!ptrs)
		return (-1);
	join_philos(&philos, args.number_of_philosophers);

	free(ptrs);
	free(philos);
	printf("cont: %d\n", cont);
}
