/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:14:01 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/03 18:16:24 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define TIMESTAMP "timestamp_in_ms"
# define FORK "has taken a fork"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define died "died"
# define EAT "is eating"

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_thread {
	pthread_t		thread_id;
	char			*string;
} t_thread;

typedef struct s_input {
	int philosophers;
	int	forks;
	int	time_to_die;
	int	time_to_sleep;
	int	numbers_of_time_eat;
	int	number_of_times_each_philosopher_must_eat;
	int	is_optional;
	struct timeval	start_time;
} t_input;

typedef struct f_fork 
{	
	long 			id;
	int 			is_used;
	pthread_mutex_t	mutex;
} t_fork;

typedef struct s_philosopher
{
	int				num;
	t_fork 			*left;
	t_fork 			*right;
	t_thread		thread;
	t_input			info;
	struct timeval	limit;
	int				eat_cnt;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	limit_mutex;
} t_philosopher;

void 		io_exception();
void 		memory_exception();
int			thread_exception();
int 		parsing_input(char **argv, t_input *info);
t_thread	*linked_list_init(int n);
int			ft_atoi(const char *s);
int 		ft_create_philosopher(t_thread *thread_array, t_input info);
void		start_philosopher(void *arg);
int			join_thread_exception();
int			mutex_exception();
int			ft_get_time(struct timeval time);
int			thread_in_fork_exception();
int 		parsing_input_when_6(char **argv, t_input *info);
void		ft_thread_state(void *arg);
#endif