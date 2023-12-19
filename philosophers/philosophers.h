#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct f_data
{
	long fork;
}	fork_array;

typedef struct a_data
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	fork_array *forks_ptr;
}	arguments;



typedef struct p_data philosophers;

struct p_data
{
	pthread_t th_id;
	int philo_Nbr;
	philosophers *right_neighbour;
	philosophers *left_neighbour;
	fork_array *left_fork;
	fork_array *right_fork;
	int cnt_to_die;
	int cnt_to_eat;
	int cnt_to_sleep;
	int nbr_of_times_eaten;
	int cnt_time_eaten;
	unsigned long long last_meal_ms;
	arguments *args;
};

// philo routine
void  *routine(void *voidptr);

// make philos
int create_philos(philosophers **philos, arguments *args);
int init_args(arguments *args, int argc, char **argv);

// post_routine
void join_philos(philosophers *philos, int number_of_philosophers);

// routine tools
void set_args_philo(philosophers *philo, struct timeval *tv);
int time_since_last_meal(philosophers *philo, struct timeval *tv);
void find_adjecent_philos(philosophers *philo);
void assign_fork_ptrs(philosophers *philo);


#endif