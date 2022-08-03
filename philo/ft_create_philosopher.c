/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:30:18 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/03 22:31:13 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_insert_fork_to_philosopher(t_philosopher *philos, t_input info, t_fork *forks)
{
	int	idx;

	idx = -1;
	while (++idx < info.philosophers - 1)
	{
		if (forks[idx].id > forks[idx + 1].id)
		{
			philos[idx].left = &forks[idx];
			philos[idx].right = &forks[idx + 1];
		}
		else
		{
			philos[idx].left = &forks[idx + 1];
			philos[idx].right = &forks[idx];
		}
	}
	if (forks[idx].id > forks[0].id)
	{
		philos[idx].left = &forks[idx];
		philos[idx].right = &forks[0];
		return ;
	}
	philos[idx].left = &forks[0];
	philos[idx].right = &forks[idx];
}

static void ft_init_philo(t_thread *thread_array, t_philosopher *philosophers, t_input info)
{
	t_thread		*temp;
	int				idx;

	idx = -1;
	temp = thread_array;
	gettimeofday(&info.start_time, NULL);
	while (++idx < info.forks)
	{
		philosophers->thread = thread_array[idx];
		philosophers->num = idx + 1;
		philosophers->info = info;
		philosophers->eat_cnt = 0;
		pthread_mutex_init(&(philosophers->limit_mutex), NULL);
		pthread_mutex_init(&(philosophers->eat_mutex), NULL);
		philosophers++;
	}
}

static t_fork	*ft_create_fork(t_fork *forks, t_input info)
{
	int				idx;
	int				sign;
	struct timeval	time;
	
	idx = -1;
	sign = 1;
	forks = malloc(sizeof(t_fork) * (info.forks + 1));
	if (!forks)
		return NULL;
	memset(forks, 0, info.forks + 1);
	while (++idx < info.forks)
	{
		gettimeofday(&time, NULL);
		forks[idx].id = time.tv_sec * sign + time.tv_usec;
		pthread_mutex_init(&forks[idx].mutex, NULL);
		sign *= -1;
	}
	return forks;
}

int ft_create_philosopher(t_thread *thread_array, t_input info)
{
	int				idx;
	t_philosopher 	*philosophers;
	t_fork			*forks;

	forks = NULL;
	philosophers = malloc(sizeof(t_philosopher) * (info.philosophers));
	if (!philosophers)
		return thread_exception();
	memset(philosophers, 0, info.philosophers);
	forks = ft_create_fork(forks, info);
	if (!forks)
		return thread_in_fork_exception();
	ft_insert_fork_to_philosopher(philosophers, info, forks);
	idx = -1;
	ft_init_philo(thread_array, philosophers, info);
	while (++idx < info.philosophers)
	  if (pthread_create(&thread_array[idx].thread_id, NULL, (void *)&start_philosopher, &philosophers[idx]) == 1)
	  	return (1);
	usleep(500);
	pthread_create(&thread_array[info.forks].thread_id, NULL, (void *)&ft_thread_state, philosophers);
	return (0);
}	