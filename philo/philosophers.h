/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:14:01 by mkim3             #+#    #+#             */
/*   Updated: 2022/07/30 19:11:09 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TIMESTAMP "timestamp_in_ms"
#define FORK "has taken a fork"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define died "died"

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_thread {
	pthread_t		thread_id;
	int				thread_num;
	char			*string;
} t_thread;

typedef struct s_input {
	int philosophers;
	int	forks;
	int	time_to_die;
	int	time_to_sleep;
	int	numbers_of_time_eat;
	pthread_t thread_id;
} t_input;

typedef struct s_timeval 
{
	long	tv_sec;
	long	tv_usec;	
}
typedef struct s_philosopher {
	struct t_chopstick *left;
	struct t_chopstick *right;
} t_philosopher;

typedef struct t_chopstick {
	int	id;
} t_chopstick;
void 		io_exception();
void 		memory_exception();
int			thread_exception();
int 		parsing_input(char **argv, t_input *info);
t_thread	*linked_list_init(int n);
int			ft_atoi(const char *s);
int 		ft_create_philosopher(t_thread *thread_array, t_input info);
void		start_philosopher(void *arg);