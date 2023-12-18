#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct a_data
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
}	arguments;

typedef struct p_data
{
	pthread_t th_id;
	int cnt_to_die;
	int cnt_to_eat;
	int cnt_to_sleep;
	int nbr_of_times_eaten;
}	philosophers;

typedef struct ptr_data
{
	philosophers *philo;
	arguments *args;
}	pointers;

#endif