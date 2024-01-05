#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct f_data
{
	pthread_mutex_t lock;
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

typedef struct s_data t_philosophers;

struct s_data
{
	pthread_t th_id;
	int philo_Nbr;
	t_philosophers *right_neighbour;
	t_philosophers *left_neighbour;
	fork_array *left_fork;
	fork_array *right_fork;
	int cnt_to_die;
	int cnt_to_eat;
	int cnt_to_sleep;
	int nbr_of_times_eaten;
	int cnt_time_eaten;
	unsigned long long last_meal_ms;
	unsigned long print_date;
	arguments *args;
};

// philo routine
void  *routine(void *voidptr);

// make philos
int create_philos(t_philosophers **philos, arguments *args);
int init_args(arguments *args, int argc, char **argv);

// post_routine
void join_philos(t_philosophers *philos, int number_of_philosophers);

// routine tools
void set_args_philo(t_philosophers *philo, struct timeval *tv);
int time_since_last_meal(t_philosophers *philo, struct timeval *tv);
void find_adjecent_philos(t_philosophers *philo);
void assign_fork_ptrs(t_philosophers *philo);


#endif