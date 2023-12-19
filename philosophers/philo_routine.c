
#include "philosophers.h"

extern pthread_mutex_t lock;

void  *routine(void *ptr)
{
	t_philosophers *philo = (t_philosophers *)ptr;
	struct timeval tv;
	int time_since_meal;

	set_args_philo(philo, &tv);
	assign_fork_ptrs(philo);
	find_adjecent_philos(philo);
	unsigned long start_eating;
	unsigned long current_time;

	while(1)
	{
		pthread_mutex_lock(&lock);
		time_since_meal = time_since_last_meal(philo, &tv);
		if(time_since_meal >= philo->args->time_to_die)
		{
			pthread_mutex_unlock(&lock);
			return (printf("philo %d died, %d ms since last ate\n", philo->philo_Nbr, time_since_meal), NULL);
		}
		philo->left_fork->fork = 1;
		philo->right_fork->fork = 1;
		gettimeofday(&tv, NULL);
		start_eating = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		while(1)
		{
			usleep(100 * 1000);
			printf("philo %d is eating...\n", philo->philo_Nbr);
			gettimeofday(&tv, NULL);
			current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
			if((current_time - start_eating) >=  philo->args->time_to_eat)
				break ;
		}
		philo->last_meal_ms = current_time;
		pthread_mutex_unlock(&lock);
		time_since_meal = time_since_last_meal(philo, &tv);
		if(time_since_meal >= philo->args->time_to_die)
			return (printf("philo %d died, %d ms since last ate\n", philo->philo_Nbr, time_since_meal), NULL);
	}
	//printf("th_id %d time since meal: %d ms\n", philo->philo_Nbr , );
	return (NULL);
}