/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:30:18 by mkim3             #+#    #+#             */
/*   Updated: 2022/07/30 22:05:52 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_philosopher(t_philosopher *philosophers, t_input info)
{
	int				idx;
	struct timeval	time;

	idx = -1;
	while (++idx < info.forks)
	{
		philosophers->left = malloc(sizeof(t_chopstick));
		philosophers->right = malloc(sizeof(t_chopstick));
		if (gettimeofday(&time, NULL) == -1)
			return (-1);
		printf("next\n");
		philosophers->left->id = time.tv_usec + time.tv_sec;
		philosophers->left->is_used = 0;
		usleep(100);
		if (gettimeofday(&time, NULL) == -1)
			return (-1);
		philosophers->right->id = time.tv_usec + time.tv_sec;
		philosophers->right->is_used = 0;
		printf("%ld " , time.tv_sec + time.tv_usec);
		philosophers++;
	}
	return (1);
}

int ft_create_philosopher(t_thread *thread_array, t_input info)
{
	int				idx;
	t_philosopher 	*philosophers;
	
	philosophers = malloc(sizeof(t_philosopher) * (info.philosophers + 1));
	if (!philosophers)
		return thread_exception();
	memset(philosophers, 0, info.philosophers);
	if (ft_philosopher(philosophers, info) == -1)
		return (1);
	idx = -1;
	while (++idx < info.philosophers)
	{
	  if (pthread_create(&thread_array[idx].thread_id, NULL, (void *)&start_philosopher, &thread_array[idx]) == 1)
	  	return (1);
	}
	return (0);
}