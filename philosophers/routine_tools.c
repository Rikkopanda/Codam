#include "philosophers.h"

void set_args_philo(t_philosophers *philo, struct timeval *tv)
{
	gettimeofday(tv, NULL);
	philo->last_meal_ms = ((*tv).tv_sec * 1000) + ((*tv).tv_usec / 1000);
	philo->cnt_to_die = philo->args->time_to_die;
	philo->cnt_time_eaten = 0;
}

int time_since_last_meal(t_philosophers *philo, struct timeval *tv)
{
	unsigned long long current_time;

	gettimeofday(tv, NULL);
	current_time = ((*tv).tv_sec * 1000) + ((*tv).tv_usec / 1000);
	return (current_time - philo->last_meal_ms);
}

void assign_fork_ptrs(t_philosophers *philo)
{
	if(philo->philo_Nbr < philo->args->number_of_philosophers)
	{
		philo->right_fork = philo->args->forks_ptr + philo->philo_Nbr - 1;
		philo->left_fork = philo->args->forks_ptr + philo->philo_Nbr;
	}
	else
	{
		philo->right_fork = philo->args->forks_ptr + philo->philo_Nbr - 1;
		philo->left_fork = philo->args->forks_ptr + 0;
	}
}

void find_adjecent_philos(t_philosophers *philo)
{
	if(philo->philo_Nbr < philo->args->number_of_philosophers)
	{
		philo->right_neighbour = &philo[1];
		printf("philo : %d adjecent right philo %d\n", philo->philo_Nbr, philo->right_neighbour->philo_Nbr);
	}
	else
	{
		philo->right_neighbour = &philo[-(philo->args->number_of_philosophers - 1)];
		printf("philo : %d adjecent right philo %d\n", philo->philo_Nbr, philo->right_neighbour->philo_Nbr);
	}
	if(philo->philo_Nbr > 1)
	{
		philo->left_neighbour = &philo[-1];
		printf("philo : %d adjecent left philo %d\n", philo->philo_Nbr, philo->left_neighbour->philo_Nbr);
	}
	else
	{
		philo->left_neighbour = &philo[philo->args->number_of_philosophers - 1];
		printf("philo : %d adjecent left philo %d\n", philo->philo_Nbr, philo->left_neighbour->philo_Nbr);
	}
}
