
#include "philosophers.h"

pthread_mutex_t print_lock;

void printfunc(t_philosophers *philo, struct timeval *tv, char *print_str)
{
	unsigned long current_time;
	unsigned long print_date;
	const int	print_interval = 500;

	gettimeofday(tv, NULL);
	current_time = ((*tv).tv_sec * 1000) + ((*tv).tv_usec / 1000);
	if(current_time >= (*philo).print_date)
	{
		pthread_mutex_lock(&print_lock);
		printf("philo %d %s", philo->philo_Nbr, print_str);
		pthread_mutex_unlock(&print_lock);
		(*philo).print_date = current_time + print_interval;
	}
}

void printfunc2(t_philosophers *philo, struct timeval *tv, char *print_str)
{
		pthread_mutex_lock(&print_lock);
		printf("philo %d %s", philo->philo_Nbr, print_str);
		pthread_mutex_unlock(&print_lock);
}

void phil_eat(t_philosophers *philo, struct timeval *tv)
{
	unsigned long start;
	unsigned long current_time;

	gettimeofday(tv, NULL);
	start = ((*tv).tv_sec * 1000) + ((*tv).tv_usec / 1000);
	while(1)
	{
		printfunc(philo, tv, "is eating...\n");
		gettimeofday(tv, NULL);
		current_time = ((*tv).tv_sec * 1000) + ((*tv).tv_usec / 1000);
		if((current_time - start) >=  philo->args->time_to_eat)
			break ;
	}
	philo->last_meal_ms = current_time;
}

void phil_sleep(t_philosophers *philo, struct timeval *tv)
{
	unsigned long start;
	unsigned long current_time;

	gettimeofday(tv, NULL);
	start = ((*tv).tv_sec * 1000) + ((*tv).tv_usec / 1000);
	while(1)
	{
		printfunc(philo, tv, " is sleeping...\n");
		gettimeofday(tv, NULL);
		current_time = ((*tv).tv_sec * 1000) + ((*tv).tv_usec / 1000);
		if((current_time - start) >=  philo->args->time_to_sleep)
			break ;
	}
}

int check_health(t_philosophers *philo, struct timeval *tv)
{
	int time_since_meal;

	time_since_meal = time_since_last_meal(philo, tv);
	if(time_since_meal >= philo->args->time_to_die)
	{
		pthread_mutex_unlock(&(*philo).left_fork->lock);
		pthread_mutex_unlock(&(*philo).right_fork->lock);
		return (printfunc(philo, tv, "died\n"), -1);
	}
	return (0);
}

void  *routine(void *ptr)
{
	t_philosophers *philo = (t_philosophers *)ptr;
	struct timeval tv;
	(*philo).print_date = 0;

	set_args_philo(philo, &tv);
	assign_fork_ptrs(philo);
	find_adjecent_philos(philo);
	while(1)
	{
		pthread_mutex_lock(&(*philo).right_fork->lock);
		pthread_mutex_lock(&(*philo).left_fork->lock);
		printfunc2(philo, &tv, "took left and right fork\n");
		if(check_health(philo, &tv) == -1)
			break ;
		phil_eat(philo, &tv);
		pthread_mutex_unlock(&(*philo).left_fork->lock);
		pthread_mutex_unlock(&(*philo).right_fork->lock);
		phil_sleep(philo, &tv);
	}
	pthread_mutex_destroy(&(*philo).left_fork->lock);
	pthread_mutex_destroy(&(*philo).right_fork->lock);
	return (NULL);
}
